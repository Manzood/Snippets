#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

int getpow (int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2 == 0) {
		int t = getpow(a, b / 2);
		return (t * t) % mod;
	}
	else {
		int t = getpow(a, (b - 1) / 2);
		return (((a * t) % mod) * t) % mod;
	}
}

