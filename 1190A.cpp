#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    ll n;
    ll m, k;
    cin >> n >> m >> k;
    vector<ll> a(m + 1);
    ll al = 0;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int r = i;
        for(int j = i + 1; j <= m; j++) {
            if((a[i] - al - 1) / k != (a[j] - al - 1) / k) {
                break;
            }
            r = j;
        }
        ans++;
        al += r - i + 1;
        i = r;
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