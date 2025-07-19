#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'a' || s[i] == 'e') {
            if(i + 1 >= n) {
                for(int j = i - 1; j <= n; j++) cout << s[j];
            }
            else {
                if(s[i + 2] != 'a' && s[i + 2] != 'e') {
                    cout << s[i - 1] << s[i] << s[i + 1] << '.';
                }
                else {
                    cout << s[i - 1] << s[i] << '.';
                }
            }
        }
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