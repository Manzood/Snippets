#include "../number_theory.cpp"
#include "bits/stdc++.h"
#include "custom/debugger.h"
using namespace std;
using namespace number_theory;

int64_t int_sqrt(int64_t x) {
    int64_t r = (int64_t)sqrtl(x) + 1;
    while (r * r > x) r--;
    return r;
}

int32_t main() {
    // int n = 10;
    // sieve(n);
    // vector <int> divisors(n + 1);
    // get_divisors(divisors);
    // debug (is_prime);

    long long val = 1000000000000000000;
    long long ans = int_sqrt(val);
    printf("%lld\n", ans);
}
