#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack - Dynamic Programming
// dp[c] = best value achievable with total weight <= c
// Time: O(n * W), Memory: O(W)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        // iterate capacity downwards so each item is used at most once
        for (int c = W; c >= w[i]; c--) {
            dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
        }
    }

    cout << dp[W] << "\n";
    return 0;
}
