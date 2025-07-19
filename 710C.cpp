#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    int x = 1;
    int d = 1;
    vector<vector<int>> ans(n + 1, vector<int> (n + 1));
    int l = n / 2 + 1, r = l;
    for(int i = 1; i <= n; i++) {
        for(int j = l; j <= r; j++) {
            ans[i][j] = x;
            x += 2;
        }
        if(l == 1) d = -d;
        l -= d, r += d;
    }
    x = 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!ans[i][j]) {
                ans[i][j] = x;
                x += 2;
            }
            cout << ans[i][j] << " \n"[j == n];
        }
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