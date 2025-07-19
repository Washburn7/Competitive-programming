#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
const int P = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    ll mx = -1e18, ans = 0, sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        sum = max(sum + a[i], a[i]);
        mx = max(mx, sum);
    }
    if(mx >= 0) {
        for(int i = 1; i <= n; i++) {
            ans = ((ans + a[i]) % P + P) % P;
        }
        for(int i = 1; i <= k; i++) {
            ans = (ans + mx) % P;
            mx = (mx * 2) % P;
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            ans = ((ans + a[i]) % P + P) % P;
        }
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