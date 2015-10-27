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
typedef pair <int, int> pii;

FILE *in, *out, *user;

char ok[] = "Correct!";
char wa[] = "Wrong Answer!";
char pres_error[] = "Output data is not correctly formatted!";

inline void message(double pts, int *txt) {
	printf("%lf\n%s\n", pts, txt);
	exit(0);
}

int main(int argc, char **argv) {

	assert(argc == 4);

	in = fopen(argv[1], "r");
	out = fopen(argv[2], "r");
	user = fopen(argv[3], "r");

	assert(in && out && user);

	return 0;

}
