#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> p(n + 1);
    for(int i = 1; i < s.size(); i++) {
        p[i] = p[i - 1] + (s[i] == '1');
    }
    bool sjf = 0;
    for(int i = 1; i + k - 1 < s.size(); i++) {
        if(p[i + k - 1] == 0) {
            if(p[n] == n - k) sjf = 1;
        }
        else if(p[i + k - 1] == k) {
            if(p[n] == k) sjf = 1;
        }
    }
    bool qls = 1;
    for(int i = 1; i + k - 1 <= n; i++) {
        
    }
    if(sjf) cout << "tokitsukaze";
    else if(qls) cout << "quailty";
    else cout << "once again";
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