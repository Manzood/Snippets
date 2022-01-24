#include "bits/stdc++.h"
using namespace std;

namespace number_theory {
    void sieve(vector<int>& prime_factors) {
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
    void divisors() {
        // WIP
    }
}
