#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++) {
        if(p[p[i]] == i) {
            cout << 2 << '\n';
            return ;
        }
    }

    cout << 3 << '\n';
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