#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    vector f(30, vector<int>(n + 1));
    vector g(30, vector<int>(n + 1));

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        int num = 0;
        for(int j = 29; j >= 0; j--) {
            f[j][i] = f[j][i - 1];
            g[j][i] = g[j][i - 1];
            if(y[i] >> j & 1) {
                num += (1 << j);
                f[j][i]++;
                if(num - 1 >= x[i]) g[j][i]++;
            }
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = 29; i >= 0; i--) {
            int fc = f[i][r] - f[i][l - 1];
            int fg = g[i][r] - g[i][l - 1];
            if(fc) {
                if(fc > 1) {
                    if(fg) {
                        ans += (1 << (i + 1)) - 1; 
                        break;
                    }
                    else {
                        ans += (1 << i);
                    }
                }
                else {
                    ans += (1 << i);
                }
            } 
        }
        cout << ans << ' ';
    }
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