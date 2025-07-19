#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 1), a(n + 1);
    for(int i = 2; i <= n; i++) cin >> b[i];
    a[1] = 1000000;
    for(int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + b[i];
    }
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
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