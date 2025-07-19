#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    for(int i = 2; i <= n; i++) {
        if(a[i][0] >= a[1][0] && a[i][1] >= a[1][1]) {
            cout << "-1\n";
            return ;
        }
    }
    cout << a[1][0] << '\n';
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