#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int x[N], y[N];
template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int _n = 0) : a(_n + 1), n(_n){}
    void init(int n) {
        a.assign(n + 1, T());
        this->n = n;
    }
    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    T sum(int x) {
        auto ans = T();
        for (int i = x; i >= 1; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin() + 1, a.end());
    vector<array<int, 2>> b(n + 1); 
    int m = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            b[++m] = a[i];
        }
    }
    int nx = 0, ny = 0;
    int cur = 0;
    for(auto [u, v] : b) {
        cur++;
        if(cur == 1) continue;
        x[++nx] = u;
        y[++ny] = v;
    }
    sort(x + 1, x + 1 + nx);
    sort(y + 1, y + 1 + ny);
    nx = unique(x + 1, x + 1 + nx) - x - 1;
    ny = unique(y + 1, y + 1 + ny) - y - 1;
    auto findx = [&](int t) {
        return lower_bound(x + 1, x + 1 + nx, t) - x;
    };
    auto findy = [&](int t) {
        return lower_bound(y + 1, y + 1 + ny, t) - y;
    };
    //cout << ny << '\n';
    map<array<int, 2>, int> cnt;
    Fenwick<int> fen(ny);
    for(int i = m; i >= 1; i--) {
        auto [u, v] = b[i];
        int rk = findy(v);
        //cout << u << ' ' << rk << '\n';
        cnt[{u, rk}] = fen.rangeSum(rk, ny);
        //cout << cnt[{u, rk}] << "\n\n";
        fen.add(rk, 1);
    }
    vector<vector<int>> g(nx + 1);
    for(int i = 1; i <= m; i++) {
        auto [u, v] = b[i];
        g[findx(u)].push_back(v);
    }
    ll ans = 0;
    for(int i = 1; i <= nx; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            if(j + 1 < g[i].size()) ans += cnt[{x[i], findy(g[i][j])}] - cnt[{x[i], findy(g[i][j + 1])}];
            else ans += cnt[{x[i], findy(g[i][j])}] + 1;
        }
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