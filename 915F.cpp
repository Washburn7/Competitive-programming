#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
struct DSU {
    vector<int> f, siz;
    DSU(int n) : f(n + 1), siz(n + 1, 1) { iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    DSU dsu1(n), dsu2(n);
    vector<array<int, 3>> g1, g2;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g1.push_back({max(a[u], a[v]), u, v});
        g2.push_back({min(a[u], a[v]), u, v});
    }
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end(), greater());
    for(auto [w, u, v] : g1) {
        int sz1 = dsu1.size(u), sz2 = dsu1.size(v);
        ans += 1ll * sz1 * sz2 * w;
        dsu1.merge(u, v);
    }
    for(auto [w, u, v] : g2) {
        int sz1 = dsu2.size(u), sz2 = dsu2.size(v);
        ans -= 1ll * sz1 * sz2 * w;
        dsu2.merge(u, v);
    }
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