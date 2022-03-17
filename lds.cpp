#include "bits/stdc++.h"
using namespace std;

// taken from cp-algorithms

const int INF = (int) 1e18;

int lds(vector<int> const& a) {
    int n = (int) a.size();
    vector<int> d(n+2, -INF);
    d[n + 1] = INF;

    for (int i = n - 1; i >= 0; i--) {
        int j = (int) (upper_bound(d.begin(), d.end(), a[i]) - d.begin() - 1);
        if (j < 0) j++;
        if (d[j+1] > a[i] && a[i] > d[j]) {
            d[j] = a[i];
        }
    }

    int ans = 0;
    for (int i = n; i >= 0; i--) {
        if (d[i] > -INF && d[i] < INF)
            ans = n - i + 1;
    }
    return ans;
}
