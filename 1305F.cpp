#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mt19937 rng(time(0));
    ll ans = n;
    auto f = [&](vector<ll> &a, int p) {
        ll x = a[p], res = 9e18;
        for(ll i = 2; i * i <= x; i++) {
            if(x % i == 0) {
                while(x % i == 0) x /= i;
                ll ans = 0;
                //cout << i << '\n';
                for(int j = 0; j < n; j++) {
                    if(j == p) continue;
                    if(a[j] < i) ans += i - a[j] % i;
                    else ans += min(a[j] % i, i - a[j] % i);
                }
                //cout << "bug " << p << ' ' << i << ' ' << ans << '\n';
                res = min(res, ans);
            }
        }
        
        if(x != 1) {
            ll ans = 0;
            for(int j = 0; j < n; j++) {
                if(j == p) continue;
                if(a[j] < x) ans += x - a[j] % x;
                else ans += min(a[j] % x, x - a[j] % x);
            }
            //cout << "bug " << p << ' ' << x << ' ' << ans << '\n';
            res = min(res, ans);
        }
        //cout << "bug1 " << p << ' ' << a[p] << ' ' << res << '\n';
        return res;
    };
    for(int t = 1; t <= 30; t++) {
        int p = rng() % n;
        ll x = a[p];
        for(ll i = x - 1; i <= x + 1; i++) {
            if(i) {
                a[p] = i;
                ans = min(ans, f(a, p) + abs(i - x));
            }
        }
        a[p] = x;
    }
    cout << ans;
    //1.最多n次，取gcd为2，把每个数变成偶数最多需要1次
    //2.操作一次以内的数至少是n/2级别，否则一定比trick1更劣
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