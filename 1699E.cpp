#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 10;
int n, m, a[N];
void solve() {
    cin >> n >> m;
    vector<int> c(m + 1), dp(m + 1, (int)1e9), buc(m + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        c[a[i]] = 1;
    }
    multiset<int> st;
    
    for(int i = 1; i <= m; i++) if(c[i]) st.insert(i), dp[i] = i, buc[i] = 1;
    int mn = *st.begin(), mx = *st.rbegin();
    int ans = INT_MAX;
    for(int i = m; i >= 1; i--) {
        for(int j = i; j <= m; j += i) {
            if(c[j]) {
                if(j / i >= i) {
                    buc[dp[j]]--;
                    dp[j] = min({dp[j], j / i, dp[j / i]});
                    buc[dp[j]]++;
                }
            }
            else {
                if(j / i >= i) {
                    dp[j] = min({dp[j], j / i, dp[j / i]});
                }
            }
        }
        //if(i <= 4) {
            //cout << i << ":\n";
            //for(auto j : st) cout << j << '\n';
        //}
        while(!buc[mx]) mx--;
        if(i <= mn) ans = min(ans, mx - i);
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