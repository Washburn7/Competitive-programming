#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    vector<array<int, 2>> a(5);
    for(int i = 1; i <= 4; i++) cin >> a[i][0] >> a[i][1];
    sort(a.begin() + 1, a.end());
    cout << (a[2][1] - a[1][1]) * (a[3][0] - a[1][0]) << '\n';
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