#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

struct element {

    bool negated;
    int val;

    element () {}
    element (int _val) {
        val = _val;
        negated = false;
    }

    void negate() {
        negated = true;
        val *= -1;
    }

};

FILE *in, *out, *user;

bool bio[75][75];

char ok[] = "Correct!";
char wa[] = "Wrong answer!";
char pres_error[] = "Output data is not correctly formatted!";
char too_much[] = "The number of operatons exceeds 100 000!";
char half[] = "The nubmer of operatons exceeds 5*R*S, but is less than 100 000!";
char neg[] = "The same element was negated twice!";

int R, S, official_sum, user_sum, moves;

element mat[75][75];

inline void message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
    exit(0);
}

inline void read_mat() {
    fscanf(in, "%d%d", &R, &S);
    for (int i = 0; i < R; ++i) {
       for (int j = 0; j < S; ++j) { 
           int x; fscanf(in, "%d", &x);
           mat[i][j] = element(x);
       }
    }
}

inline void rotr(int r, int k) {

    if (k < 1 || k >= S || r < 0 || r >= R) 
        message(0, pres_error);
    
    element tmp[75];
    for (int i = S - k; i < S; ++i) tmp[i - S + k] = mat[r][i];
    for (int i = S - 1; i >= k; --i) mat[r][i] = mat[r][i - k];
    for (int i = 0; i < k; ++i) mat[r][i] = tmp[i];

}

inline void rotc(int s, int k) {

    if (k < 1 || k >= R || s < 0 || s >= S)
        message(0, pres_error);

    element tmp[75];
    for (int i = R - k; i < R; ++i) tmp[i - R + k] = mat[i][s];
    for (int i = R - 1; i >= k; --i) mat[i][s] = mat[i - k][s];
    for (int i = 0; i < k; ++i) mat[i][s] = tmp[i];
}

inline void negr(int r) {
    if (r < 0 || r >= R) message(0, pres_error);
    for (int i = 0; i < S; ++i) {
        if (mat[r][i].negated) message(0, neg);
        mat[r][i].negate();
    }
}

inline void negc(int s) {
    if (s < 0 || s >= S) message(0, pres_error);
    for (int i = 0; i < R; ++i) {
        if (mat[i][s].negated) message(0, neg);
        mat[i][s].negate();
    }
}   

int get_sum() {
   int ret = 0;
   for (int i = 0; i < R; ++i)
       for (int j = 0; j < S; ++j)
           ret += mat[i][j].val;
    return ret;
}

void simulate(double pts, char *txt) {

    for (int i = 0; i < moves; ++i) {
        char type[10];
        if (fscanf(user, "%s", type) != 1)
            message(0, pres_error);
        if (type[0] == 'r') {
            int a, b;
            if (fscanf(user, "%d%d", &a, &b) != 2)
                message(0, pres_error);
            if (type[3] == 'R') rotr(a - 1, b); else rotc(a - 1, b);
        } else {
            int x;
            if (fscanf(user, "%d", &x) != 1)
                message(0, pres_error);
            if (type[3] == 'R') negr(x - 1); else negc(x - 1);
        }
    }

    char dummy[2];
    if (fscanf(user, "%1s", dummy) == 1)
        message(0, pres_error);

    if (get_sum() == official_sum)
        message(pts, txt);
    else
        message(0, wa);

}

int main(int argc, char **argv) {

    assert(argc == 4);

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "r");
    user = fopen(argv[3], "r");

    assert(in && out && user);

    read_mat();

    fscanf(out, "%d", &official_sum);
    if (fscanf(user, "%d", &user_sum) != 1) 
        message(0, pres_error);

    if (official_sum != user_sum) 
        message(0, wa);

    if (fscanf(user, "%d", &moves) != 1)
        message(0, pres_error);

    if (moves > 100000)
        message(0, too_much);

    if (moves <= 5 * R * S)
        simulate(1, ok);
    else 
        simulate(0.5, half);

    return 0;

}
