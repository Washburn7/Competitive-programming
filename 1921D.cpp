#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1), sa(n + 1), sb(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    for(int i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
    for(int i = 1; i <= m; i++) sb[i] = sb[i - 1] + b[i];
    vector<int> stl(n + 1), str(n + 2);
    ll ans = 0;
    // stl[0] = 1;
    // for(int i = 1; i <= n; i++) {
    //     if(b[m - i + 1] >= a[i]) stl[i] |= stl[i - 1];    
    // }
    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ' << sa[i] << "\n";    
    // }
    // for(int i = 1; i <= m; i++) {
    //     cout << b[i] << ' ' << sb[i] << "\n";    
    // }
    for(int i = 0; i <= n; i++) {
        // if(stl[i]) {
        //     if(i != n && a[i + 1] < b[n - i]) continue;
        //     cout << "nice: " << i << '\n';
        //     ll res = sb[m] - sb[m - n] - sa[i] + sa[n] - sa[i] - sb[n - i + 1];        
        //     ans = max(ans, res);
        // }
        //cout << i << ' ' << sb[m] - sb[m - i] - sa[i] + sa[n] - sa[i] - sb[n - i + 1] << '\n';
        //cout << sb[m] << ' ' << sb[m - i] << '\n';
        ans = max(ans, sb[m] - sb[m - i] - sa[i] + sa[n] - sa[i] - sb[n - i]);
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