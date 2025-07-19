#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int c1 = 0, c2 = 0;
    map<int, int> cnt;
    int n;
    cin >> n;
    ll s = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s += x;
        cnt[x]++;
    }
    for(auto [u, v] : cnt) {
        if(v >= 3) c1++;
        if(v == 2) c2++;
    }
    if(c1 >= 1 || c2 >= 2) cout << "cslnb";
    else {
        if(c2 == 1) {
            bool ok = 1;
            for(auto [u, v] : cnt) {
                if(v == 2) {
                    if(cnt.count(u - 1)) {
                        ok = 0;
                        break;
                    }
                }
            }
            if(!ok || cnt[0] == 2) {
                cout << "cslnb";
                return ;
            }
        }
        ll x = s - 1ll * (n - 1) * n / 2;
        if(x % 2 == 0) cout << "cslnb";
        else cout << "sjfnb";
    } 
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