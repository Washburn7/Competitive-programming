#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), s(n + 1);
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
        mp[s[i]].push_back(i);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        int v = s[r] ^ s[l - 1];
        if(v == 0) {
            // auto pos = lower_bound(mp[0].begin(), mp[0].end(), l);
            // if(pos == mp[0].end()) {
            //     cout << "NO\n";
            // }
            // else {
            //     //cout << *pos << '\n';
            //     if(*pos < r) {
            //         cout << "YES\n";
            //     }
            //     else {
            //         cout << "NO\n";
            //     }
            // }
            cout << "YES\n";
        } 
        else {
            auto pos1 = lower_bound(mp[s[l - 1] ^ v].begin(), mp[s[l - 1] ^ v].end(), l);
            if(pos1 == mp[s[l - 1] ^ v].end()) {
                cout << "NO\n";
            }
            else {
                if(*pos1 > r) {
                    cout << "NO\n";
                }
                else {
                    int p1 = *pos1;
                    auto pos2 = lower_bound(mp[s[p1] ^ v].begin(), mp[s[p1] ^ v].end(), p1 + 1);
                    if(pos2 == mp[s[p1] ^ v].end()) {
                        cout << "NO\n";
                    }
                    else {
                        int p2 = *pos2;
                        if(p2 < r) {
                            cout << "YES\n";
                        }
                        else {
                            cout << "NO\n";
                        }
                    }
                }
            }
        }
    }
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