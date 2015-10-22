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
char area[] = "The smallest painted area is correct, but number of swoops is not!";
char swoops[] = "The smallest number of swoops is correct, but the painted area is not!";
char pres_error[] = "Output data is not correctly formatted!";

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

    int x1, y1;
    fscanf(out, "%d%d", &x1, &y1);

    int x2, y2;
    if (fscanf(user, "%d%d", &x2, &y2) != 2) 
        message(0, pres_error);

    char dummy[2];
    if (fscanf(user, "%1s", dummy) == 1)
        message(0, pres_error);

    if (x1 != x2 && y1 != y2) message(0, wa);
    if (x1 == x2 && y1 != y2) message(0.5, area);
    if (x1 != x2 && y1 == y2) message(0.5, swoops);
    if (x1 == x2 && y1 == y2) message(1, ok);
    
    return 0;

}
