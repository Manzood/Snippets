#include "bits/stdc++.h"
using namespace std;

constexpr int mod = (int)1e9 + 7;

// https://codeforces.com/blog/entry/23365
// calculates inv of a wrt m, same complexity as the extended euclidean algo
// a and m must be positive coprime integers
long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

int getpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        int t = getpow(a, b / 2);
        return (t * t) % mod;
    } else {
        int t = getpow(a, (b - 1) / 2);
        return (((a * t) % mod) * t) % mod;
    }
}

// (a / b) % MOD = a * ((b ^ (MOD - 2)) % MOD;
// ONLY works if MOD is prime
// if they're coprime, you'll probably need the euler's totient function
int divide(int a, int b) { return a * getpow(b, mod - 2) % mod; }

// finding the modular inverse of every number modulo mod
// currently using it as a black box, study it sometime
void getmod(vector<int>& inv) {
    inv[1] = 1;
    for (int i = 2; i < mod; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
}

// refer to https://cp-algorithms.com/algebra/module-inverse.html

// will update this in the future
// x is the inverse of a, y is a / mod
// int get_inverse (int a, int y) {
//     int x;
//     // x needs to be returned
//     int g = extended_euclidean (a, mod, x, y);
// }
