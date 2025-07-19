#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 3e5 + 10;
const int P = 998244353;
int n, a[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    i64 ans = 0;
    for(int i = 0; i < 30; i++) {
        vector<int> s(n + 1);
        i64 s0 = 0, s1 = 0;
        int c0 = 1, c1 = 0;
        for(int j = 1; j <= n; j++) {
            s[j] = (s[j - 1] ^ (a[j] >> i & 1));
            //if(i <= 3) cout << i << ' ' << j << ' ' << s[j] << '\n';
            if(s[j] == 1) {
                ans = (ans + (1ll * c0 * j % P - s0 + P) % P * (1 << i) % P) % P;
                c1++;
                s1 = (s1 + j) % P;
            }
            else {
                ans = (ans + (1ll * c1 * j % P - s1 + P) % P * (1 << i) % P) % P;
                c0++;
                s0 = (s0 + j) % P;
            }
            //if(i == 0) cout << j << ' ' << ans << ' ' << ;
        }
        //cout << i << ' ' << ans << '\n';
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