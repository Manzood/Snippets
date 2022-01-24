#include "bits/stdc++.h"
#include "custom/debugger.h"
#include "../sieve.cpp"
using namespace std;

int32_t main() {
    int n = 10;
    vector <int> primes(n + 1);
    sieve(primes);
    debug (primes);
}
