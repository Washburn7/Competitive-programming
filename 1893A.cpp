#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), vis(n);
    bool ans = 1;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= k; i++) {
        int p = (cur - 1 + n) % n;
        if(vis[p]) {
            break;
        }
        else {
            if(b[p] > n) {
                ans = 0;
                break;
            }
            cur = (cur - b[p] + n) % n;
            vis[p] = 1;
        }
    }
    if(ans) cout << "YES\n";
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