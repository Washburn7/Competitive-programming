#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    string s;
    cin >> s;
    i64 ans = 0;
    int last = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            if(last) ans += last + 1;
        }
        else {
            last++;
        }
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