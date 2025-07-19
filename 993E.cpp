#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> dp(n + 1, 1e18);
    for(int i = 1; i <= n; i++) {
        dp[i] = min({dp[i], dp[i - 1] + x, dp[(i + 1) / 2] + y + x})
    }
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;

    while(t--) {
        solve();
    }

    return 0;
}