#include "bits/stdc++.h"
using namespace std;

namespace number_theory {
    vector<int> primes_list;
    vector<bool> is_prime;
    const int N = 0;
    void sieve(int n) {
        is_prime.resize(n + 1);
        is_prime.assign(n + 1, true);
        primes_list.clear();
        is_prime[0] = false;
        is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (!is_prime[i]) continue;
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
            primes_list.push_back(i);
        }
    }
    void sieve() { // make sure to redefine N as your global constant if you're going to be copy/pasting this into your code
        is_prime.resize(N + 1);
        primes_list.clear();
        is_prime.assign(N + 1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (int i = 2; i <= N; i++) {
            if (!is_prime[i]) continue;
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            primes_list.push_back(i);
        }
    }
    void get_prime_factors(vector<int>& prime_factors) {
        int n = (int)prime_factors.size();
        prime_factors.assign(n, 0);
        for (int i = 2; i <= n; i++) {
            if (prime_factors[i] == 0) {
                for (int j = i; j <= n; j += i) {
                    prime_factors[j]++;
                }
            }
        }
    }
    void get_divisors(vector<int>& divisors) {
        int n = (int)divisors.size();
        divisors.assign(n, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divisors[j]++;
            }
        }
    }
}  // namespace number_theory
