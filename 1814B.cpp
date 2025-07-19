#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = INT_MAX;
    for(int i = 0; i <= 100000; i++) {
        int m = i + 1;
        ans = min(ans, (a + m - 1) / m + (b + m - 1) / m + i);
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