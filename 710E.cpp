#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i & 1) dp[i] = min({dp[i], dp[i - 1] + x, dp[(i + 1) / 2] + y + x});
        else dp[i] = min({dp[i], dp[i - 1] + x, dp[i / 2] + y});
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