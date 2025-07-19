#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i][1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0];
        if(a[i][0] < 0) a[i][0] *= -1;
    }
    sort(a.begin() + 1, a.end());
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i][1];
        ll need = (sum + k - 1) / k;
        if(need > a[i][0]) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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