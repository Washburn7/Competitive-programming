#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
constexpr int P = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for(int i = 0; i <= n; i++) dp[0][i] = 1;
    for(int i = 0; i < n; i++) {
        for(int x = 0; x <= n; x++) {
            for(int y = 0; i + x * y + x + y + 1 <= n && x + y + 1 <= k; y++) {
                dp[i + x * y + x + y + 1][y] = (dp[i + x * y + x + y + 1][y] + dp[i][x]) % P;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) ans = (ans + dp[n][i]) % P;
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