#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    ll n, b, x;
    cin >> n >> b >> x;
    vector<int> c(n + 1);
    int sum = 0;
    int mx = 0;
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        sum += c[i];
        mx = max(mx, c[i]);
        res += 1ll * c[i] * (c[i] - 1) / 2 * b;
    }
    ll ans = -9e18;
    vector<ll> c1(mx + 1), c2(mx + 1);
    for(int i = 1; i <= n; i++) {
        c1[c[i]] += c[i];
        c2[c[i]]++;
    }
    for(int i = 1; i <= mx; i++) {
        c1[i] += c1[i - 1];
        c2[i] += c2[i - 1];
    }
    for(int i = 1; i <= sum; i++) {
        ll cur = -1ll * (i - 1) * x;
        for(int j = 0; j <= mx; j += i) {
            int x = max(j, 1), y = min(mx, j + i - 1);
            ll cnt1 = c1[y] - c1[x - 1], cnt2 = c2[y] - c2[x - 1];
            cnt1 = cnt1 - (cnt2 * j);
            ll s = cnt2 * i - cnt1;
            //cout << i << ' ' << j << ' ' << cnt1 <<  ' ' << s << '\n';
            cur -= cnt1 * (j / i + 1) * (j / i) / 2 * b + s * (j / i) * (j / i - 1) / 2 * b;
        }
        ans = max(ans, cur + res);
        //cout << i << ' ' << cur << '\n';
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