#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n + 2, 1e9), r(n + 2);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        l[x] = min(l[x], i);
        r[x] = max(r[x], i);
    }
    int x = 0, y = n + 1;
    for(int i = 0; i <= n + 1; i++) {
        if(l[i] > r[i]) {
            if(i == 0) {
                cout << 2 << '\n';
                cout << 1 << ' ' << n - 1 << '\n';
                cout << n << ' ' << n << '\n';
                return ;
            }
            else {
                cout << 2 << '\n';
                cout << 1 << ' ' << y - 1 << '\n';
                cout << y << ' ' << n << '\n';
                return ;
            }
        }
        else if(l[i] == r[i]) {
            break;
        }
        else {
            x = max(x, l[i]);
            y = min(y, r[i]);
            if(x > y) break;
        }
    }
    cout << -1 << '\n';
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