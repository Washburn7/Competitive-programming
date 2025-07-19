#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int n, k, a[N];
i64 sum[1010][1010], dp[1010][1010], res[N], ans;
const int P = 998244353;
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int mx = *max_element(a + 1, a + 1 + n);
    for(int i = 1; i <= mx; i++) {
        if(1ll * i * (k - 1) > mx) break;
        dp[0][0] = sum[0][0] = 1;
        int R = 0;
        for(int j = 1; j <= n; j++) {
            while(R + 1 < j && a[j] - a[R + 1] >= i) R++;
            for(int o = 0; o <= k && o <= j; o++) {
                if(o == 0) {
                    sum[j][o] = sum[j - 1][o];
                    continue;
                }
                dp[j][o] = sum[R][o - 1];
                sum[j][o] = (sum[j - 1][o] + dp[j][o]) % P;
            }
        }
        res[i] = sum[n][k];
        ans = (ans + res[i]) % P;
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