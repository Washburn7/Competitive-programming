#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    int sa = 0, sb = 0;
    for(int i = 0; i < a.size(); i++) {
        
        if(a[i] != b[i]) {
            if(a[i] == '1') sa++;
            if(b[i] == '1') sb++;
        }
    }
    cout << max(sa, sb) << '\n';
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