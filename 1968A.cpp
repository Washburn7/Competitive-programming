#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    int mx = 0, ans = 0;
    for(int i = 1; i < n; i++) {
        if(gcd(i, n) + i > mx) mx = gcd(i, n) + i, ans = i;
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