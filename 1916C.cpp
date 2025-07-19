#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x = 0, y = 0;
    ll s = 0;
    auto get = [&](int x, int y) {
        if(x % 3 != 1) {
            return x / 3;
        }
        else {
            return x / 3 + 1;
        }
    };
    for(int i = 1; i <= n; i++) {
        if(a[i] & 1) x++;
        else y++;
        s += a[i];
        if(i == 1) {
            cout << s << ' ';
            continue;
        }
        cout << s - get(x, y) << ' '; 
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