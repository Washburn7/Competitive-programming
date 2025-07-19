#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int _n = 0) : a(_n + 1), n(_n){}
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

struct Max {
    int v;
    Max(int x = 0) : v{x} {}//注意范围
    
    Max &operator+=(Max a) {
        v = std::max(v, a.v);
        return *this;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] -= i;
    auto b = a;
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
    auto find = [&](int x) {
        return upper_bound(b.begin() + 1, b.end(), x) - b.begin() - 1;
    };
    const int M = b.size();
    Fenwick<Max> fen1(M), fen2(M), fen3(M);
    vector<int> p(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++) {
        int pos = find(a[i]);
        p[i] = fen1.sum(pos).v + 1;
        fen1.add(pos, p[i]);
    }
    for(int i = n; i >= 1; i--) {
        int pos = M - find(a[i]) + 1;
        s[i] = fen2.sum(pos).v + 1;
        fen2.add(pos, s[i]);
    }
    int ans = n;
    for(int i = 1; i < n; i++) ans = min(ans, n - p[i] - 1);
    for(int i = 2; i <= n; i++) ans = min(ans, n - s[i] - 1);
    //for(int i = 1; i <= n; i++) cout << i << ' ' << a[i] << ' ' << p[i] << ' ' << s[i] << '\n';
    for(int i = 2; i <= n; i++) {
        int pos = find(a[i] + 1);
        ans = min(ans, n - (s[i] + fen3.sum(pos).v) - 1);
        pos = find(a[i - 1]);
        fen3.add(pos, p[i - 1]);
        if(a[i] >= a[i - 1]) ans = min(ans, n - (p[i - 1] + s[i]));
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