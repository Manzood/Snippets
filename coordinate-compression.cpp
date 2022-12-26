#include "bits/stdc++.h"
using namespace std;

void coordinate_compression(vector<int>& a) {
    int n = (int)a.size();
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        a[i] = (int)(lower_bound(d.begin(), d.end(), a[i]) - d.begin());
    }
}
