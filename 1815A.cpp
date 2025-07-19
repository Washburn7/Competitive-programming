#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n & 1) cout << "YES\n";
    else {
        ll sum = 0;
        for(int i = 2; i <= n; i += 2) sum += a[i] - a[i - 1];
        if(sum < 0) cout << "NO\n";
        else cout << "YES\n";
    }
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