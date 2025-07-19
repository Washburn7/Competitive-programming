#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
const int P = 1e9 + 7;
int a[N], pos[N], s[N];
void solve() {
    int n, m;
    cin >> n >> m;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 1) pos[++cur] = i;
        s[i] = s[i - 1] + a[i];
    }
    vector dp(n + 1, vector<ll>(m + 1));
    vector ndp(n + 1, vector<ll>);
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int op = i % 2;
        for(int j = 0; j <= cur; j++) {
            for(int k = 0; k <= m; k++) {
                dp[op][j][k] = (dp[op][j][k] + dp[op ^ 1][j][k]) % P;
                if(j - 1 >= 0) {
                    if(k + abs(i - pos[j]) <= m) {
                        dp[op][j][k + abs(i - pos[j])] = (dp[op][j][k + abs(i - pos[j])] + dp[op ^ 1][j][k]) % P;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i = k; i >= 0; i -= 2) {
        ans = (ans + dp[n % 2]);
    }


    /*先考虑最终的序列，对于每一种最终的序列，交换次数的奇偶性是确定的。因为有k的限制，
    不妨考虑最少的交换次数，能够发现第一个1最终还要是第一个1，那么移动次数就是每个1的位置的差
    的绝对值。然后可以想到n^3的dp，会超时。怎么办呢？我们来探索一下dp有没有什么限制，最终
    的序列到第i个位置1的个数与初始序列第i个位置1的个数最多相差sqrt(k)数量级，为什么？如果不满足
    这个条件那肯定得把多出来或少掉的1给移动进前i个位置或者移出前i个位置，那么
    移动次数是O(需要移动的1的个数^2)级别，那就只考虑相差不超过sqrt(k)的情况就行，
    实际相差的会比sqrt(k)大一些，这样dp就是n^2*sqrt(k)的级别了。
    */
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