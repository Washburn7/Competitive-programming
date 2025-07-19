#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, a, b;
    ll f;
    cin >> n >> f >> a >> b;
    vector<int> m(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> m[i];
    }
    for(int i = 0; i < n; i++) {
        ll d = m[i + 1] - m[i];
        if(d * a > b) f -= b;
        else f -= d * a;
    }
    if(f > 0) cout << "YES\n";
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