#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, x;
    cin >> n >> x;
    int ans = -1;
    vector<int> a(n + 1);
    vector<int> cbit(31);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 30; j++) {
            if(a[i] >> j & 1) {
                cbit[j]++;
            }
        }
    }
    int cur = 0;
    bool no = 0;
    for(int i = 30; i >= 0; i--) {
        if(x >> i & 1) {
            if(cbit[i] & 1) continue;
            cur += (1 << i);
            int cnt = 0, xo = 0;
            for(int j = 1; j <= n; j++) {
                xo ^= a[j];
                bool nice = 1;
                for(int k = 0; k < 31; k++) {
                    if(cur >> k & 1) {
                        if(xo >> k & 1) {
                            nice = 0;
                            break;
                        }
                    }
                }
                if(nice) xo = 0, cnt++;
            }
            if(i <= 4) {
                //cout << "bug  " << i << ' ' << xo << ' ' << cnt << '\n';
            }
            if(cnt != 0 && !xo) ans = max(ans, cnt);
            cur -= (1 << i);
        }
        else {
            if(cbit[i] & 1) {
                no = 1;
                break;
            }
            cur += (1 << i);
        }
    }
    if(!no) {
        int cnt = 0, xo = 0;
        for(int j = 1; j <= n; j++) {
            xo ^= a[j];
            bool nice = 1;
            for(int k = 0; k < 31; k++) {
                if(cur >> k & 1) {
                    //cout << k << '\n';
                    if(xo >> k & 1) {
                        nice = 0;
                        break;
                    }
                }
            }
            if(nice) xo = 0, cnt++;
        }
        //cout << "lastbug  " << cnt << ' ' << xo << '\n';
        if(cnt != 0 && xo == 0) ans = max(ans, cnt);
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