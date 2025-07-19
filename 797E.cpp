#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
constexpr int B = sqrt(100000);
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(B + 1, vector<int> (n + 1)); 
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= B; i++) {
        for(int j = n; j >= 1; j--) {
            if(j + a[j] + i > n) dp[i][j] = 1;
            else dp[i][j] = dp[i][j + a[j] + i] + 1;
        }
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int p, k;
        cin >> p >> k;
        if(k <= B) cout << dp[k][p] << '\n';
        else {
            int cur = p, ans = 0;
            while(cur <= n) {
                ans++;
                cur = cur + a[cur] + k;
            }
            cout << ans << '\n';
        }
    }
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