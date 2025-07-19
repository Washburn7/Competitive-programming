#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    ll a = 0, b = 0;
    bool ans = 0;
    map<ll, int> cnt;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if(i & 1) a += x;
        else b += x;
        if(cnt.count(a - b)) ans = 1;
        cnt[a - b] = 1;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
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