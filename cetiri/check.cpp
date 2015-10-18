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
char pres_error[] = "Output data is not correctly formatted!";

int a[5];

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

int main(int argc, char **argv) {

    if (argc <= 3) {
        fprintf(stderr, "usage: check <input> <official> <contestant>");
        return 1;
    }

    in = fopen(argv[1], "r"); assert(in != NULL);
    out = fopen(argv[2], "r"); assert(out != NULL);
    user = fopen(argv[3], "r"); assert(user != NULL);

    fscanf(in, "%d%d%d", &a[0], &a[1], &a[2]);
    
    if (fscanf(user, "%d", &a[3]) != 1) {
        message(0, pres_error);
        return 0;
    }

    if (check_end()) 
        return 0;

    sort(a, a + 4);

    int x = a[1] - a[0];
    if (a[2] - a[1] != x || a[3] - a[2] != x)
        message(0, wa);
    else
        message(1, ok);

    return 0;

}

