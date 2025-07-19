#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    vector<ll> f(50);
    f[0] = f[1] = 1;
    for(int i = 2; i < 50; i++) f[i] = f[i - 1] + f[i - 2];
    int n;
    ll x, y;
    cin >> n >> x >> y;
    ll a, b, c, d;
    a = 1, b = 1, c = f[n], d = f[n + 1];
    for(int i = n; i >= 1; i--) {
        //cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        if((a + f[i] - 1 < x || b + f[i] - 1 < y) && (a + f[i] - 1 <= c && b + f[i] - 1 <= d)) {
            if(a + f[i] - 1 == c) b += f[i];
            else a += f[i];
            continue;
        }
        if((a + f[i] - 1 < x || d - f[i] + 1 > y) && (a + f[i] - 1 <= c && d - f[i] + 1 >= b)) {
            if(a + f[i] - 1 == c) d -= f[i];
            else a += f[i];
            continue;
        }
        if((c - f[i] + 1 > x || b + f[i] - 1 < y) && (c - f[i] + 1 >= a && b + f[i] - 1 <= d)) {
            if(c - f[i] + 1 == a) b += f[i];
            else c -= f[i];
            continue;
        }
        if((c - f[i] + 1 > x || d - f[i] + 1 > y) && (c - f[i] + 1 >= a && d - f[i] + 1 >= b)) {
            if(c - f[i] + 1 == a) d -= f[i];
            else c -= f[i];
            continue;
        }
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
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