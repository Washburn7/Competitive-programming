#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == b[i] && !a[i]) {
            ans[i] = 4;
            continue;
        }
        int res = 0;
        while(a[i]) {
            //cout << i << ' ' << a[i] << ' ' << b[i] << ' ' << res << '\n';
            if(b[i]) {
                if(a[i] < b[i]) {
                    res = (res + 1) % 3;
                    int c = abs(a[i] - b[i]);
                    a[i] = b[i];
                    b[i] = c;
                }
                else {
                    int cnt = a[i] / (2 * b[i]);
                    if(cnt) a[i] -= cnt * b[i] * 2;
                    else {
                        res = (res + 1) % 3;
                        int c = abs(a[i] - b[i]);
                        a[i] = b[i];
                        b[i] = c;
                    }
                }
            }
            else {
                res = (res + 2) % 3;
                break;
            }
        }
        if(!a[i]) res = (res + 1) % 3;
        ans[i] = res;
    }
    bool nice = 1;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        //cout << i << ' ' << ans[i] << '\n';
        if(ans[i] != 4) v.push_back(ans[i]);
    }
    
    
    for(int i = 1; i < v.size(); i++) {
        if(v[i] != v[i - 1]) {
            nice = 0;
        }
    }
    if(nice) cout << "YES\n";
    else cout << "NO\n";
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