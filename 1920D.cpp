#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1), x(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i] >> x[i];
    }
    bool nice = 0;
    ll cur = 0;
    map<ll, int> mp;
    vector<array<ll, 3>> v;
    for(int i = 1; i <= n; i++) {
        if(b[i] == 2) {
            if(!nice) continue;
            if(cur >= (ll)1e18 / (x[i] + 1)) {
                v.push_back({2, cur + 1, (ll)1e18});
                break;
            }
            else {
                v.push_back({2, cur + 1, cur * (x[i] + 1)});
                cur = cur * (x[i] + 1);
            }
        }
        else {
            if(b[i] == 1) {
                nice = 1;
                int r = i;
                ll L = cur + 1;
                for(int j = i; j <= n; j++) {
                    if(b[j] != 1) break;
                    r = j;
                    mp[++cur] = x[j];
                }
                ll R = cur;
                v.push_back({1, L, R});
                i = r;
            }
        }
    }
    // for(auto [x, y, z] : v) {
    //     cout << x << ' ' << y << ' ' << z << '\n';
    // }
    while(q--) {
        ll k;
        cin >> k;
        k--;
        int pos;
        for(int i = 0; i < v.size(); i++) {
            if(v[i][2] - 1 >= k && v[i][1] - 1 <= k) {
                pos = i;
                break;
            }
        }
        for(int i = pos; i >= 0; i--) {
            //cout << k << '\n';
            if(v[i][0] == 1) {
                if(v[i][2] - 1 >= k && v[i][1] - 1 <= k) {
                    cout << mp[k + 1] << ' ';
                    break;
                }
            }
            else {
                k = k % (v[i][1] - 1);
            }
        }
    }
    cout << '\n';
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