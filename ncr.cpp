#include "bits/stdc++.h"
using namespace std;

int ncr (int n, int r) {
    int retval = 1;
    for (int i = 1; i <= n; i++) {
        retval *= (n - r + 1);
        retval /= i;
    }
    return retval;
}
