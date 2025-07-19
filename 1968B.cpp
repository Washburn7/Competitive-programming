#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    string s, t;
    int n, m;
    cin >> n >> m;
    cin >> s >> t;
    s = ' ' + s, t = ' ' + t;
    int r = 0;
    int ans = 0;
    for(int i = 1; i < s.size(); i++) {
        while(r + 1 < t.size() && t[r] != s[i]) {
            r++;
        }
        if(r >= t.size() || t[r] != s[i]) break;
        //cout << i << ' ' << r << '\n';
        ans = i;
        r++;
    }
    cout << ans << '\n';
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