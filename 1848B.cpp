#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(k + 1);
    for(int i = 1; i <= n; i++) {
        g[a[i]].push_back(i);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++) {
        g[i].push_back(n + 1);
        int mx1 = 0, mx2 = 0;
        for(int j = 0; j < g[i].size(); j++) {
            int last = 0;
            if(j != 0) last = g[i][j - 1];
            int d = g[i][j] - last - 1;
            if(d > mx1) {
                mx2 = mx1;
                mx1 = d;
            }
            else if(d > mx2) {
                mx2 = d;
            }
        }
        //cout << i << ' ' << mx1 << ' ' << mx2 << ' ' << max(mx2, mx1 / 2) << '\n';
        ans = min(ans, max(mx2, mx1 / 2));
    }
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