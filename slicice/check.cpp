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

#define MAXN 105
#define MAXM 1005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

FILE *in, *out, *user;

char ok[] = "Correct!";
char wa[] = "Wrong answer!";
char pres_error[] = "Output data is not correctly formatted!";

int n, m, k;
int total[MAXN], a[MAXM], b[MAXM];
int cnt[MAXN][MAXN];

inline void message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
    exit(0);
}

inline bool in_bounds(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < 3;
}

int main(int argc, char **argv) {

    assert(argc == 4);

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "r");
    user = fopen(argv[3], "r");

    assert(in && out && user);

    fscanf(in, "%d%d", &n, &m);
    for (int i = 0; i < n; ++i) 
        fscanf(in, "%d", &total[i]);

    for (int i = 0; i < m; ++i) {
        fscanf(in, "%d%d", &a[i], &b[i]);
        --a[i]; --b[i];
        ++cnt[a[i]][b[i]];
        ++cnt[b[i]][a[i]];
    }

    if (fscanf(user, "%d", &k) != 1 || k > 1000) 
        message(0, pres_error);

    for (int i = 0; i < k; ++i) {
        
        int x1, x2, y1, y2; 
        if (fscanf(user, "%d%d%d", &x1, &x2, &y1) != 3) 
            message(0, pres_error);
        
        --x1; --x2; y2 = 2 - y1;
        if (!in_bounds(x1, y1) || !in_bounds(x2, y2)) 
            message(0, pres_error);
        
        total[x1] -= y1;
        total[x2] -= y2;

        --cnt[x1][x2];
        --cnt[x2][x1];

    }

    char dummy[2];
    if (fscanf(user, "%1s", dummy) == 1)
        message(0, pres_error);

    bool pass = true;

    for (int i = 0; i < n; ++i)
        pass &= total[i] == 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            pass &= cnt[i][j] <= 0;

    if (pass)
        message(1, ok);
    else
        message(0, wa);

    return 0;

}
