#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int cur = 0;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        //cout << i << ' ' << cur << '\n';
        ans += (1ll * cnt[i] * (cnt[i] - 1) / 2) * cur;
        ans += (1ll * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
        cur += cnt[i];
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