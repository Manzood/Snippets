#include "bits/stdc++.h"
using namespace std;

class dsu {
   public:
    vector<int> p, size;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }
    int parent(int x) {
        // path compression
        if (x == p[x])
            return x;
        else
            return p[x] = parent(p[x]);
    }
    inline bool unite(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x != y) {
            if (size[x] > size[y]) swap(x, y);
            p[x] = y;
            size[y] += size[x];
            return true;
        }
        return false;
    }
};
