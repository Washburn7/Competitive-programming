#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
ll n, m;
ll get(ll x, ll y, ll z) {
    return y * x + y * (y - 1) / 2 * z; 
}
void solve() {
    cin >> n >> m;

    ll mx = -1, ans = -1;
    for(int k = 1; k <= m; k++) {
        if(k >= n) {
            vector<int> st(n + 1);
            ll x = 0;
            for(int i = 1; i <= n; i++) {
                st[i] = 1;
                ll j = (i * k - 1 + n) % n + 1;
                if(!st[j]) st[j] = 1, x += j;
            }
            if(x > mx) mx = x, ans = k;
        }
        else {
            ll res = 0;
            ll g = gcd(n, k);
            ll l = k;

            vector<int> vis(k + 1);
            ll step = 0;
            while(1) {
                if(vis[l]) break;
                vis[l] = 1;
                ll len = (n - l) / k + 1;

                auto check = [&](ll m) {
                    ll r = l + (m - 1) * k;
                    if(step + m >= r) {
                        return 1;
                    }
                    else {
                        return 0;
                    }
                };
                ll lo = 0, hi = len;
                while(lo < hi) {
                    ll m = lo + hi + 1 >> 1;
                    if(check(m)) {
                        lo = m;
                    }
                    else {
                        hi = m - 1;
                    }
                }
                step += len;
                //cout << k << ' ' << l << ' ' << len << ' ' << lo << '\n';
                res += get(l, len, k) - get(l, lo, k);
                l = l + len * k;
                l %= n;
            }
            //cout << k << ' ' << res << '\n';

            if(res > mx) {
                mx = res, ans = k;
            }
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