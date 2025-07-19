#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    int ans = 0, lst = 0, cur = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x > lst) cur++;
        else cur = 1;
        lst = x;
        ans = max(ans, cur);
    }
    cout << ans;
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