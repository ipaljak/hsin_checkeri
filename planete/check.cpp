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

#define MAXN 205

using namespace std;

int dayz[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {

	int d, m;

	date () {}
	date (int _d, int _m) {
		d = _d;
		m = _m;
	}

};

typedef long long llint;
typedef pair <int, int> pii;

FILE *in, *out, *user;

char ok[] = "Correct!";
char wa[] = "Wrong Answer!";
char pres_error[] = "Output data is not correctly formatted!";

const int mod = 365;

int n, m;
int duration[MAXN]; 

inline void message(double pts, char *txt) {
	printf("%lf\n%s\n", pts, txt);
	exit(0);
}

date day_to_date(int d) {
	int m = 0;
	while (d > dayz[m]) 
		d -= dayz[m++];
	return date(d, m + 1);
}

int date_to_day(date D) {
	int ret = D.d; 
	for (int i = 0; i < D.m - 1; ++i) ret += dayz[i];
	return ret % mod;
}

void check_solution() {

	for (int i = 0; i < n; ++i) {
		
		int d1, m1, d2, m2;
		fscanf(in, "%d%d%d%d", &d1, &m1, &d2, &m2);
		
		int from = date_to_day(date(d1, m1));
		int to   = date_to_day(date(d2, m2));

		for (int i = 0; i < m; ++i) {
			int koef; 
			fscanf(in, "%d", &koef);
			from += koef * duration[i];
			from %= mod;
		}

		if (from != to) message(0, wa);
	
	}

	message(1, ok);

}

int main(int argc, char **argv) {

	assert(argc == 4);

	in = fopen(argv[1], "r");
	out = fopen(argv[2], "r");
	user = fopen(argv[3], "r");

	assert(in && out && user);

	fscanf(in, "%d%d", &n, &m);
	
	int off;
	fscanf(out, "%d", &off);

	if (fscanf(user, "%d", &duration[0]) != 1) 
		message(0, pres_error);

	if (off == -1)
		if (off == duration[0])
			message(1, ok);
		else
			message(0, wa);
	
	if (duration[0] < 1 || duration[0] > 365)
		message(0, pres_error);

	for (int i = 1; i < m; ++i) {
		if (fscanf(user, "%d", &duration[i]) != 1)
			message(0, pres_error);
		if (duration[i] < 1 || duration[i] > 365)
			message(0, pres_error);
	}

	char dummy[2];
	if (fscanf(user, "%1s", dummy) == 1) 
		message(0, pres_error);

	check_solution();
	
	return 0;

}
