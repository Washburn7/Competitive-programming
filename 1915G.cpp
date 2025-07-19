#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<array<ll, 2>>> g(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<ll> S(n + 1);
    for(int i = 1; i <= n; i++) cin >> S[i];
    auto dij = [&](auto &g, int s, int n) {
        vector<vector<ll>> d(n + 1, vector<ll> (1000 + 1, -1));
        vector<vector<int>> st(n + 1, vector<int> (1000 + 1));
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
        pq.push({0, s, S[s]});
        while(!pq.empty()) {
            auto [dist, u, cur] = pq.top();
            pq.pop();
            if(st[u][cur]) continue;
            st[u][cur] = 1;
            for(auto [v, w] : g[u]) {
                if(d[v][min(cur, S[v])] == -1 || d[v][min(cur, S[v])] > dist + w * cur) {
                    //cout << v << ' ' << min(cur, S[v]) << ' ' << dist << "\n";
                    pq.push({d[v][min(cur, S[v])] = dist + w * cur, v, min(cur, S[v])});
                }
            }
        }
        return d;
    };
    auto d = dij(g, 1, n);
    ll ans = LLONG_MAX;
    //cout << d[3][1] << ' ' << d[2][2] << '\n';
    for(int i = 1; i <= 1000; i++) {
        if(d[n][i] != -1) ans = min(ans, d[n][i]);
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