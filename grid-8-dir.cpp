#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
