#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    ll ans1 = a * min(k, d) + (d - min(d, k)) * b;
    ll ans2 = 0, ans3 = 0;
    if(d % k == 0) {
        ans2 = (d / k - 1) * (a * k + t) + a * k;
        if(d == k) ans3 = b * k;
        else ans3 = (d / k - 1) * (a * k + t) - t + b * k;
    }
    else {
        ans2 = (d / k) * (a * k + t) + (d % k) * a;
        if(d < k) ans3 = b * d;
        else ans3 = (d / k) * (a * k + t) - t + b * (d % k);
    }
    //cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
    cout << min({ans1, ans2, ans3});
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