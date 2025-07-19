#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int n, a[N], b[N], c[N], d[N];
const int P = 998244353;
void solve() {
    cin >> n;
    map<int, int> cnt; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        cnt[a[i]] = b[i];
    }
    int m;
    cin >> m;
    ll ans = 1;
    for(int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    int c1 = n;
    for(int i = 1; i <= m; i++) {
        cin >> d[i];
        if(cnt[c[i]] < d[i]) ans = 0;
        else {
            if(cnt[c[i]] == d[i]) c1--; 
        }
    }
    if(c1 > 0) {
        for(int i = 1; i <= c1; i++) ans = ans * 2 % P;
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