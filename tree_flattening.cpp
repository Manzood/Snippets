#include "bits/stdc++.h"
using namespace std;

int tree_loc;
vector <bool> visited;

// flattens the tree by following an Euler tour through it, adding nodes to the flattened array as they are visited and left
void dfs_flattening(int node, vector<int> &a, vector<vector<int>> &adj, vector<int> &start, vector<int> &end, vector<int> &flattened) {
    if (visited[node]) return;
    flattened.push_back(a[node]);
    visited[node] = true;
    start[node] = tree_loc++;

    for (auto u : adj[node]) {
        dfs_flattening(u, a, adj, start, end, flattened);
    }

    end[node] = tree_loc++;
    flattened.push_back(a[node]);
}

int main () {
    // flatten the tree
    int n;
    vector <int> a(n);      // contains the values for nodes
    vector <vector <int>> adj(n);       // stores graph

    tree_loc = 0;           // stores the indices while travelling past the tree
    visited.resize(n, false);
    visited.assign(n, false);
    vector <int> flattened, start(n), end(n);       // stores the flattened tree, while start and end can be used to find the range for each individual subtree
    dfs_flattening(0, a, adj, start, end, flattened); // function that flattens the tree, making it
    // ready for queries
}
