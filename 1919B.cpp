#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0, len = 0;
    for(char c : s) {
        if(c == '-') {
            cur--;
            len++;
        }
        else {
            cur++;
            len++;
        }
        if(cur == 0) {
            len = 0;
        }
    }
    cout << abs(cur) << '\n';
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