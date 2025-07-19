#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
vector<array<int, 2>> g[20];
ll dp[20];
pair<int, int> from[20];
ll a[N];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    g[0].push_back({1, 1}); // 0 -> 1
    g[1].push_back({1, 1}); // 0 0 -> 1 0
    g[1].push_back({1, 2}); // 1 0 -> 2 2
    for(int i = 2; i < 20; i++) {
        for(int j = 0; j < g[i - 1].size(); j++) {
            g[i].push_back({g[i - 1][j][0], g[i - 1][j][1]});
        } //2 0 0
        g[i].push_back({2, i});
        for(int j = 0; j < g[i - 1].size() - 1; j++) {
            g[i].push_back({g[i - 1][j][0] + 1, g[i - 1][j][1] + 1});
        }
        g[i].push_back({1, i + 1});
        //cout << i << ' ' << g[i].size() << '\n';
    }
    // for(auto [x, y] : g[3]) {
    //     cout << x << ' ' << y << '\n';
    // }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(j == i + 1) {
                if(dp[i] + a[j] > dp[j]) {
                    dp[j] = dp[i] + a[j];
                    from[j] = {i, -1};
                }
                if(dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    from[j] = {i, 1};
                }
            }
            else {
                if(dp[i] + (j - i) * (j - i) > dp[j]) {
                    dp[j] = dp[i] + (j - i) * (j - i);
                    from[j] = {i, 1};
                }
            }
        }
    }
    cout << dp[n] << ' ';
    vector<array<int, 2>> ans;
    int cur = n;
    while(cur) {
        if(from[cur].second == 1) {
            int len = cur - from[cur].first;
            int last = from[cur].first;
            for(int i = g[len - 1].size() - 1; i >= 0; i--) {
                ans.push_back({last + g[len - 1][i][0], last + g[len - 1][i][1]});
            }
            for(int i = last + 1; i <= cur; i++) {
                if(a[i] != 0) ans.push_back({i, i});
            }
        }
        cur = from[cur].first;
    } 
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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