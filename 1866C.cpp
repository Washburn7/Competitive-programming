#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
const int P = 998244353;
int n, s[N];
vector<array<int, 2>> g[N];
ll ans;
ll res[N], cnt[N][2];
bool st[N];
ll sz;
void dfs(int u) {
    for(auto [v, w] : g[u]) {
        if(w) sz = (sz + 1) % P;
        ll csz = sz;
        bool first = 0;
        if(!st[v]) {
            st[v] = 1;
            first = 1;
            dfs(v);
            ans = (ans + csz * (w == 0)) % P;
            cout << u << ' ' << v << ' ' << csz << ' ' << (w == 0) << '\n';
        }
        else {
            sz = (sz + cnt[v][1]) % P;
            ans = (ans + csz * (w == 0)) % P;
            cout << u << ' ' << v << ' ' << csz << ' ' << (w == 0) << '\n';
        }
        ans = (ans + res[v]) % P;
        res[u] = (res[u] + res[v]) % P;

        //cout << u << ' ' << v << ' ' << csz << ' ' << cnt[v][0] << " plus " << csz * cnt[v][0] << '\n';
        cnt[u][0] = (cnt[u][0] + cnt[v][0] + (w == 0)) % P;
        cnt[u][1] = (cnt[u][1] + cnt[v][1] + (w == 1)) % P;  
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++) {
            int x, y;
            cin >> x >> y;
            g[i].push_back({x, y});
        }
    }
    dfs(1);
    cout << ans;
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