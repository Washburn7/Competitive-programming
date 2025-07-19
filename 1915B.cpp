#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    map<char, int> cnt;
    for(int i = 1; i <= 3; i++) {
        string s;
        cin >> s;
        for(char c : s) cnt[c]++;
    }
    for(char i = 'A'; i <= 'C'; i++) {
        if(cnt[i] != 3) cout << i << '\n';
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