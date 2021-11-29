#include "bits/stdc++.h"
using namespace std;

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;

int main() {
    // max heap
    priority_queue<int> max_pq;

    // min heap
    priority_queue<int, vector<int>, greater<int> > min_pq;
}
