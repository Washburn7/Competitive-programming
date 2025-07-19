#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<i64> a(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector dp(n + 1, vector<i64>(k + 1, 1e18));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = max(1, i - k); j <= i; j++) {
            for(int o = i; o <= min(n, i + k); o++) {
                if(o - j <= k) {
                    int len = o - j + 1;
                    for(int last = 0; last <= k; last++) {
                        if(len - 1 + last > k) break;
                        dp[o][len - 1 + last] = min(dp[o][len - 1 + last], dp[j - 1][last] + 1ll * len * a[i]);
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    i64 ans = 9e18;
    for(int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;

    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}