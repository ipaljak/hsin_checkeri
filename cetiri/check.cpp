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

FILE *in, *out, *user;

char wa[] = "Wrong answer!";
char ok[] = "Correct!";

int a[5];

inline void message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
} 

int main(int argc, char **argv) {

    if (argc <= 3) {
        fprintf(stderr, "usage: check <input> <official> <contestant>");
        return 1;
    }

    in = fopen(argv[1], "r"); assert(in != NULL);
    out = fopen(argv[2], "r"); assert(out != NULL);
    user = fopen(argv[3], "r"); assert(user != NULL);

    fscanf(in, "%d%d%d", &a[0], &a[1], &a[2]);
    fscanf(user, "%d", &a[3]);

    sort(a, a + 4);

    int x = a[1] - a[0];
    if (a[2] - a[1] != x || a[3] - a[2] != x)
        message(0, wa);
    else
        message(1, ok);

    return 0;

}

