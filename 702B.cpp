#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    map<ll, int> cnt;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        for(ll j = 0; j < 35; j++) {
            if(cnt.count((1ll << j) - x))
                ans += cnt[(1ll << j) - x];
        }
        cnt[x]++;
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