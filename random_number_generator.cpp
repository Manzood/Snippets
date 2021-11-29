#include "bits/stdc++.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    // this is how you print a random number between 0 and 10, using rng
    int n = uniform_int_distribution<int>(0, 10)(rng);
    printf("%d\n", n);
}
