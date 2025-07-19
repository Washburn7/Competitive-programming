#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int n, a[N], s[N];
int pos[51][1300];
vector<int> pos[1500 * 1500];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    vector<int> sum;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            sum.push_back(s[j] - s[i - 1]);
        }
    }

    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int p = lower_bound(sum.begin(), sum.end(), s[i] - s[j - 1]) - sum.begin();
            pos[p].push_back({j, i});
        }
    }
    int ans = 0, ansl, ansr;
    for(int t = 0; t < sum.size(); t++) {
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++) {
            if(pos[i][t]) {
                int j = pos[i][t];
                int mx = 0;
                for(int k = j - 1; k >= 1; k--) {
                    if(dp[k] > dp[mx]) mx = k;
                }
                dp[i][t] = dp[mx][t] + 1;
                from[i][t] = mx;
            }
        }
    }
    for(int t = 0; t < sum.size(); t++) {
        for(int i = 1; i <= n; i++) {
            if(dp[i][t] > ans) ans = dp[i][t], ansl = i, ansr = t;
        }
    }
    cout << ans << '\n';
    vector<pair<int, int>> res;
    while(ansl != 0) {
        res.push_back({pos[ansl][ansr], ansl});
        ansl = from[ansl][ansr];
    }
    for(auto [l, r] : res) cout << l << ' ' << r << '\n';
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