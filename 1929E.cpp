#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1), f(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        for(int v : g[u]) {
            if(v == fa) continue;
            d[v] = d[u] + 1;
            f[v] = u;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    int k;
    cin >> k;

    vector<int> s(n + 1);    
    auto modify = [&](int x, int y, int z) {
        while(d[x] != d[y]) {
            if(d[x] > d[y]) {
                s[x] |= (1 << z);
                x = f[x];
            }
            else {
                s[y] |= (1 << z);
                y = f[y];
            }
        }
        while(x != y) {
            s[x] |= (1 << z);
            x = f[x];
            s[y] |= (1 << z);
            y = f[y];
        }
    };

    for(int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        modify(a, b, i - 1);
    }

    sort(s.begin() + 1, s.end());
    s.erase(unique(s.begin() + 1, s.end()), s.end());

    int sz = s.size();
    for(int i = 0; i < sz - 1; i++) {
        s[i] = s[i + 1];
    }
    sz--;

    vector<int> dp(1 << k, 1e9);
    dp[0] = 0;
    for(int i = 0; i < (1 << k); i++) {
        for(int j = 0; j < sz; j++) {
            dp[i | s[j]] = min(dp[i | s[j]], dp[i] + 1);
        }
    }
    cout << dp[(1 << k) - 1] << '\n';
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