#include "bits/stdc++.h"
using namespace std;
#define int long long

const int mod = (int) 1e9 + 7;

// slow, takes O(n) time;
// long long ncr (long long n, long long r) {
//     long long retval = 1;
//     for (int i = 1; i <= n; i++) {
//         retval *= (n - r + 1);
//         retval /= i;
//     }
//     return retval;
// }

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
int divide(int a, int b) { return a * getpow(b, mod - 2) % mod; }


// precomputation takes O(n + logm) time
vector <long long> fact, inverse_fact;
void precompute_factorials (long long n) {
    fact.resize(n + 1);
    inverse_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inverse_fact[n] = getpow(n, mod - 2) % mod;
    for (int i = n - 1; i >= 0; i--) {
        inverse_fact[i] = inverse_fact[i+1] * (i + 1) % mod;
    }
}

// returns in O(1) time
long long ncr (int n, int r) {
    if (r > n || n < 0  || r < 0) return 0; // extra safety conditions
    return (((fact[n] * inverse_fact[r]) % mod) * inverse_fact[n-r] % mod);
}

