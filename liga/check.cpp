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

#define MAXN 10

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

FILE *in, *out, *user;

char ok[] = "Correct!";
char wa[] = "Wrong answer, some lines are not correct!";
char pres_error[] = "Output data is not correctly formatted!";

int n;
int a[MAXN], b[MAXN];

inline void message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
}

inline bool check_end() {
    char dummy[2];
    if (fscanf(user, "%1s", dummy) == 1) {
        message(0, pres_error);
        return true;
    }
    return false;
}

inline bool check_line() {
    for (int i = 0; i < 5; ++i)
        if (a[i] != b[i]) return false;
    return true;
}

int main(int argc, char **argv) {

    if (argc <= 3) {
        fprintf(stderr, "usage: check <input> <official> <contestant>");
        return 1;
    }

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "r");
    user = fopen(argv[3], "r");

    assert(in && out && user);

    fscanf(in, "%d", &n);
    
    int pass = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) fscanf(out, "%d", &a[j]);
        for (int j = 0; j < 5; ++j) {
            if (fscanf(user, "%d", &b[j]) != 1) {
                message(0, pres_error);
                return 0;
            }
        }
        pass += check_line();
    }

    if (check_end()) 
        return 0;

    if (pass == n)
        message(1, ok);
    else
        message((double) pass / n, wa);

    return 0;

}

