#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    vector<int> w(n + 1), s(n + 1);
    auto get = [&](int x, int y) {
        if(x > y) {
            return (x - y - 1) * ql;
        }
        else if(x < y) {
            return (y - x - 1) * qr;
        }
        else {
            return 0;
        }
    };
    for(int i = 1; i <= n; i++) cin >> w[i], s[i] = s[i - 1] + w[i];
    int ans = INT_MAX;
    for(int i = 0; i <= n; i++) {
        int x = (s[i] - s[0]) * l + (s[n] - s[i]) * r;
        ans = min(ans, x + get(i, n - i));
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