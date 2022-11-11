#include "bits/stdc++.h"

// taken from https://codeforces.com/blog/entry/107717
// works upto int64_t, using O(log n) time complexity

int64_t int_sqrt(int64_t x) {
    int64_t r = (int64_t)sqrtl(x) + 1;
    while (r * r > x) r--;
    return r;
}
