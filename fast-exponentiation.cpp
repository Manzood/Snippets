#include "bits/stdc++.h"
using namespace std;

// use for doubles
double getpow (double a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2 == 0) {
		double t = getpow(a, b / 2);
		return t * t;
	} else {
		double t = getpow(a, (b - 1) / 2);
		return a * t * t;
	}
}

// long long intgers
long long power (long long a, long long b, long long m) {
	long long result = 1;
	while (b) {
		if (b % 2 == 1) result = result * a % m;
		a = a * a % m;
		b /= 2;
	}
	return result;
}
