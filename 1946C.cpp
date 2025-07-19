#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lo = 1, hi = n;

    auto check = [&](int m) {
        vector<int> sz(n + 1), del(n + 1);
        int cnt = 0;
        function<void(int, int)> dfs = [&](int u, int fa) {
            sz[u] = 1;
            for(int v : g[u]) {
                if(v == fa) continue;
                dfs(v, u);
            }
            for(int v : g[u]) {
                if(v == fa) continue;
                if(!del[v]) {
                    sz[u] += sz[v];
                }
            }
            if(u != 1) {
                if(sz[u] >= m) cnt++, del[u] = 1;//, cout << "dfs  " << u << ' ' << sz[u] << '\n';
            }
        };
        dfs(1, 0);
        //cout << "debug " << m << ' ' << cnt << ' ' << sz[1] << '\n';
        if(cnt > k) return 1;
        else if(cnt == k) {
            if(sz[1] >= m) return 1;
            else return 0;
        }   
        else return 0;
    };
    while(lo < hi) {
        int m = lo + hi + 1 >> 1;
        if(check(m)) lo = m;
        else hi = m - 1;
    }

    cout << lo << '\n';
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