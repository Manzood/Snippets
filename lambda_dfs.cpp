#include "bits/stdc++.h"
using namespace std;

int32_t main () {
    int n = 0;
    vector <bool> visited(n);
    vector <vector <int>> adj(n);

    auto dfs = [&] (auto& self, int node) -> void {
        visited[node] = true;
        for (auto u: adj[node]) {
            if (!visited[u]) self(self, u);
        }
    };

    // usage
    dfs (dfs, 0); // do a dfs from node 0
}
