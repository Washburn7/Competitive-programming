#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    bool eq = 0;
    for(int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        if(x == a && y == b) eq = 1;
        if((x + y) % 2 == (a + b) % 2) cnt++;
    }
    if(eq) {
        cout << "NO\n";
    }
    else {
        if(cnt && (n == 1 || m == 1)) {
            cout << "NO\n";
        }
        else if(cnt) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
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