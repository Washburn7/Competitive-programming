#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = 1; i <= n; i++) {
        
    }
    vector<int> vis(1000);
    for(int i = a; i <= b; i++) {
        for(int j = c; j <= d; j++) {
            vis[(i | j)] = 1;
        }
    }
    for(int i = 0; i <= 100; i++) {
        cout << i << ' ' << vis[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;

    while(t--) {
        solve();
    }

    return 0;
}