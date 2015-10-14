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

#define MAXN 500005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

FILE *in, *out, *user;

char wa[] = "Wrong answer! The number of moves is not minimal.";
char half[] = "The number of moves is correct, but the sequence is not!";
char ok[] = "Correct!";

int n, q, head;
int prev[MAXN], next[MAXN];

inline void init() {
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    } 
    next[n - 1] = -1;
}

void find_head() {
    for (int i = 0; i < n; ++i)
        if (prev[i] == -1) head = i;
}

inline void print_list() {
    find_head();
    for (int i = head; i != -1; i = next[i])
        printf("%d ", i + 1);
    printf("\n");
}

inline int message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
    return 0;
}

bool all_fine() {
    find_head();
    int curr = 0;
    for (int i = head; i != -1; i = next[i]) 
        if (i != curr++) return false;
    return true;
}

int shuffle_list(FILE *fin, int m) {
    
    char t[3];
    int a, b; 
    
    for (int i = 0; i < m; ++i) {
        fscanf(fin, "%s%d%d", t, &a, &b); --a; --b;
        prev[next[a]] = prev[a];
        next[prev[a]] = next[a];
        if (t[0] == 'A') {
            prev[a] = prev[b];
            next[a] = b;
        } else {
            prev[a] = b;
            next[a] = next[b];
        }
        next[prev[a]] = a;
        prev[next[a]] = a;
    }
}

int main(int argc, char **argv) {

    if (argc <= 3) {
        fprintf(stderr, "usage: check <input> <official> <contestant>");
        return 1;
    }

    in = fopen(argv[1], "r"); assert(in != NULL);
    out = fopen(argv[2], "r"); assert(out != NULL);
    user = fopen(argv[3], "r"); assert(user != NULL);

    fscanf(in, "%d%d", &n, &q);
    init();

    shuffle_list(in, q);
   
    int k1, k2;
    fscanf(out, "%d", &k1);
    fscanf(user, "%d", &k2);

    if (k1 != k2)
        return message(0, wa);

    shuffle_list(user, k2);

    if (all_fine())
        return message(1, ok);
    else
        return message(0.6, half);

    return 0;

}

