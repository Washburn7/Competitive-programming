#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int rd1 = min({x1, y1, n - x1 + 1, n - y1 + 1});
    int rd2 = min({x2, y2, n - x2 + 1, n - y2 + 1});
    cout << abs(rd1 - rd2) << '\n';
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