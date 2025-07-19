#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int y[N];
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
    vector<array<ll, 2>> a(n + 1);
    int m = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][1] = -a[i][1];
        y[++m] = a[i][1];
    }
    sort(y + 1, y + 1 + m);
    m = unique(y + 1, y + 1 + m) - y - 1;
    //cout << m << '\n';
    Fenwick<int> fen(m);
    auto find = [&](ll t) {
        return lower_bound(y + 1, y + 1 + m, t) - y;
    };
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += fen.rangeSum(1, find(a[i][1]));
        fen.add(find(a[i][1]), 1);
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