#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> col(n + 1);
    for(int i = 1; i <= n; i++) cin >> col[i];
    int tim = 0;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(m + 1);
    vector<vector<pair<int, int>>> qry(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, k;
        cin >> u >> k;
        qry[u].push_back({k, i});
    }
    vector<int> heavy(n + 1), l(n + 1), r(n + 1), sz(n + 1, 1), id(n + 1);
    vector<int> cnt(100001), res(n + 1);
    function <void(int, int)> dfs_init = [&](int u, int fa) {
        l[u] = ++tim;
        id[tim] = u;
        for(auto v : g[u]) {
            if(v == fa)
                continue;
            dfs_init(v, u);
            sz[u] += sz[v];
            if(!heavy[u] || sz[v] > sz[heavy[u]]) heavy[u] = v;
        }
        r[u] = tim;
    };
    function <void(int, int, bool)> dfs_solve = [&](int u, int fa, bool keep) {
        for(auto v : g[u]) {
            if(v == fa || v == heavy[u])
                continue;
            dfs_solve(v, u, 0);
        }
        if(heavy[u]) dfs_solve(heavy[u], u, 1);
        auto add = [&](int x) {
            cnt[col[x]]++;
            res[cnt[col[x]]]++;
        };
        auto query = [&](int x) {

        };
        auto del = [&](int x) {
            res[cnt[col[x]]]--;
            cnt[col[x]]--;
        };
        for(auto v : g[u]) {
            if(v == fa || v == heavy[u])
                continue;
            // for(int i = l[v]; i <= r[v]; i++)
            //     query(id[i]);
            for(int i = l[v]; i <= r[v]; i++)
                add(id[i]);
        }
        //query(u);
        add(u);
        for(auto &[k, id] : qry[u]) {
            ans[id] = res[k];
        }
        if(!keep) {
            for(int i = 1; i <= sz[u]; i++) res[i] = 0;
            for(int i = l[u]; i <= r[u]; i++) cnt[col[i]] = 0;
            // for(int i = l[u]; i <= r[u]; i++)
            //     del(id[i]);
        }
    };
    dfs_init(1, 0);
    dfs_solve(1, 0, 0);
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
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