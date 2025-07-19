#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

multiset<pair<int, int>> st[N]; 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), sum(n + 1);
    vector<int> sz(n + 1), f(n + 1), heavy(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto fun = [&](int x) {
        if(st[x].empty()) heavy[x] = 0;
        else {
            auto pos = st[x].begin();
            heavy[x] = pos -> second;
        }
    };
    function<void(int, int)> dfs = [&](int u, int fa) {
        f[u] = fa;
        sz[u] = 1;
        sum[u] = a[u];
        for(int v : g[u]) {
            if(v == fa) continue;
            dfs(v, u);
            sum[u] += sum[v];
            st[u].insert({-sz[v], v});
            if(!heavy[u]) heavy[u] = v;
            else {
                if(sz[v] == sz[heavy[u]]) {
                    heavy[u] = min(heavy[u], v);
                }
                else if(sz[v] < sz[heavy[u]]){
                    heavy[u] = v;
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(1, 0);
    while(m--) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            cout << sum[x] << '\n';
        }
        else {
            if(!heavy[x]) continue;
            int son = heavy[x], fa = f[x];
            st[x].erase({-sz[son], son});
            st[fa].erase({-sz[x], x});
            ll tx = sz[x], ty = sz[son];
            sz[son] = tx;
            sz[x] = tx - ty;
            tx = sum[x], ty = sum[son];
            sum[son] = tx;
            sum[x] = tx - ty;
            f[son] = fa;
            f[x] = son;
            st[fa].insert({-sz[son], son});
            st[son].insert({-sz[x], x});
            fun(fa);
            fun(son);
            fun(x);
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