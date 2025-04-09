#include "bits/stdc++.h"
using namespace std;

// taken from cp-algorithms

const int INF = (int)1e18;

int lis(vector<int> const& a) {
    int n = (int)a.size();
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = (int)(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if (d[j - 1] < a[i] && a[i] < d[j]) d[j] = a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] < INF) ans = i;
    }

    return ans;
}
