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

char ok[] = "Correct!";
char wa[] = "Wrong answer!";
char pres_error[] = "Output data is not correctly formatted!";

vector <int> v1, v2;

inline void message(double pts, char *txt) {
    printf("%lf\n%s\n", pts, txt);
    exit(0);
}

int main(int argc, char **argv) {

    assert(argc == 4);

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "r");
    user = fopen(argv[3], "r");

    assert(in && out && user);

    int x;
    while (fscanf(out, "%d", &x) == 1) 
        v1.push_back(x);

    while (fscanf(user, "%d", &x) == 1) 
        v2.push_back(x);

    char dummy[2];
    if (fscanf(user, "%1s", dummy) == 1)
        message(0, pres_error);

    if (v1.size() != v2.size())
        message(0, wa);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < (int) v1.size(); ++i) 
        if (v1[i] != v2[i]) message(0, wa);

    message(1, ok);

    return 0;

}
