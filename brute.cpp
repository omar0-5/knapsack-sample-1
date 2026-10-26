#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack - Brute Force
// Try every subset of items using a bitmask.
// Time: O(2^n * n)  -> only usable for n <= ~20
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    long long best = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long weight = 0, value = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                weight += w[i];
                value += v[i];
            }
        }
        if (weight <= W) best = max(best, value);
    }

    cout << best << "\n";
    return 0;
}
