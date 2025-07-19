#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    auto dij = [&](auto &g, int s, int n) {
        vector<ll> d(n + 1, -1);
        vector<int> st(n + 1);
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
        pq.push({0, s});
        while(!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if(st[u]) continue;
            st[u] = 1;
            for(auto [v, w] : g[u]) {
                if(d[v] == -1 || d[v] > dist + w) {
                    pq.push({d[v] = dist + w, v});
                }
            }
        }
        return d;
    };
    int n, m;
    cin >> n >> m;
    vector<vector<array<ll, 2>>> g(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, 2 * w});
        g[v].push_back({u, 2 * w});
    }
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        g[0].push_back({i, x});
    }
    auto d = dij(g, 0, n);
    for(int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
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