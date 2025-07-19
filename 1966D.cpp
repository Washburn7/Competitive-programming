#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int a[N];
void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    do {
        vector<int> dp(n + 1);
        dp[0] = 1;
        bool f1 = 0;
        if(a[1] == 1 && a[2] == 2 && a[3] == 8 && a[4] == 3) {
            //cout << "yes\n";
            f1 = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j + a[i] <= n; j++) {
                if(dp[j]) {
                    dp[j + a[i]] = 1;
                }
            }
            if(i == 4 && f1) {
                for(int j = 1; j <= n; j++) {
                    cout << j << ' ' << dp[j] << '\n';
                }
                return ;
            }
            // if(dp[k]) {
                
            //     break;
            // }
            bool nice = 1;
            for(int j = 1; j <= n; j++) {
                if(j == k) continue;
                if(!dp[j]) nice = 0;
            }
            if(nice) {
                for(int j = 1; j <= i; j++) cout << a[j] << ' ';
                return ;
            }
        }
    } while(next_permutation(a + 1, a + 1 + n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}