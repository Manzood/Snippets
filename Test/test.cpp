#include "bits/stdc++.h"
#include "custom/debugger.h"
#include "../number_theory.cpp"
using namespace std;
using namespace number_theory;

int32_t main() {
    int n = 10;
    vector <int> primes(n + 1);
    sieve(primes);
    debug (primes);
}
