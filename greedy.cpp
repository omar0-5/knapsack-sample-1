#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack - Greedy by value/weight ratio
// NOTE: this is NOT always optimal for 0/1 knapsack
// (it is only optimal for the fractional version).
// Time: O(n log n)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    // sort by ratio v/w descending, compared without floating point:
    // v[a]/w[a] > v[b]/w[b]  <=>  v[a]*w[b] > v[b]*w[a]
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return 1LL * v[a] * w[b] > 1LL * v[b] * w[a];
    });

    long long remaining = W, total = 0;
    for (int i : idx) {
        if (w[i] <= remaining) {   // take the whole item if it fits
            remaining -= w[i];
            total += v[i];
        }
    }

    cout << total << "\n";
    return 0;
}
