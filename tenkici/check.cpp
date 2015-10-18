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

#define MAXN 505

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

struct move {
    
    int id, d; 
    
    move () {}
    move (int _id, int _d) {
        id = _id;
        d = _d;
    }

};

FILE *in, *out, *user;

bool tenk[MAXN][MAXN];

char wa[] = "Wrong answer! The number of moves is not minimal.";
char half[] = "The number of moves is correct, but the sequence is not!";
char ok[] = "Correct!";
char pres_error[] = "Output data is not correctly formatted!";

int n;
int r[MAXN], s[MAXN];

int dr[] = {1, 0, -1, 0};
int ds[] = {0, 1, 0, -1};

vector <move> v;

map <char, int> dir;

inline void init() {
    dir['D'] = 0;
    dir['R'] = 1;
    dir['U'] = 2;
    dir['L'] = 3;
}

inline int message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
    return 0;
}
    
inline bool check_end() {
    char dummy[2];
    return fscanf(user, "%1s", dummy) == 1;
}

void fill_grid() {
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; ++i) {
        fscanf(in, "%d%d", &r[i], &s[i]);
        --r[i]; --s[i];
        tenk[r[i]][s[i]] = true;
    }
}

inline bool empty(int r, int s) {
    return r >= 0 && r < n && s >= 0 && s < n && !tenk[r][s];
}

inline bool all_fine() {
    for (int i = 0; i < n; ++i) {
        int rc = 0, cc = 0;
        for (int j = 0; j < n; ++j) {
            rc += tenk[i][j];
            cc += tenk[j][i];
        }
        if (rc != 1 || cc != 1) 
            return false;
    }
    return true;
}

int check() {

    int k1, k2;

    fscanf(out, "%d", &k1);
    if (fscanf(user, "%d", &k2) != 1) {
        message(0, pres_error);
        exit(0);
    }

    if (k1 != k2)
        return message(0, wa);

    int t; char st[2];
    while (fscanf(user, "%d%1s", &t, st) == 2) {
        if (dir.find(st[0]) == dir.end() || strlen(st) != 1)
            return message(0.6, half);
        v.push_back(move(t - 1, dir[st[0]]));
    }

    if ((int) v.size() != k1) 
        return message(0.6, half);

    for (int i = 0; i < (int) v.size(); ++i) {

        int r1 = r[v[i].id], s1 = s[v[i].id];
        int r2 = r1 + dr[v[i].d], s2 = s1 + ds[v[i].d]; 

        if (!empty(r2, s2))
            return message(0.6, half);
    
        tenk[r1][s1] = false;
        tenk[r2][s2] = true;

        r[v[i].id] = r2;
        s[v[i].id] = s2;

    }

    if (all_fine() && !check_end())
        return message(1, ok);
    else 
        return message(0.6, half);

}

int main(int argc, char **argv) {

    init();

    if (argc <= 3) {
        fprintf(stderr, "usage: check <input> <sluzbeno> <output>\n");
        return 1;
    }

    in = fopen(argv[1], "r"); assert(in != NULL);
    out = fopen(argv[2], "r"); assert(out != NULL);
    user = fopen(argv[3], "r"); assert(user != NULL);

    fill_grid();
    return check();

}

