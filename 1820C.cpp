#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> l, r;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(!l.count(a[i])) {
            l[a[i]] = i;
            r[a[i]] = i;
        }
        else {
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }
    }
    int mex = 0;
    for(int i = 0; i != -1; i++) {
        if(!l.count(i)) {
            mex = i;
            break;
        }
    }
    if(l.count(mex + 1)) {
        int L = l[mex + 1], R = r[mex + 1];
        for(int i = L; i <= R; i++) {
            a[i] = mex;
        }
        map<int, int> cnt;
        for(int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        for(int i = 0; i != -1; i++) {
            if(!cnt.count(i)) {
                if(i == mex + 1) {
                    cout << "YES\n";
                }
                else cout << "NO\n";
                break;
            }
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(a[i] > mex) {
                cout << "YES\n";
                return ;
            }
            else {
                if(l[a[i]] != r[a[i]]) {
                    cout << "YES\n";
                    return ;
                }
            }
        }
        cout << "NO\n";
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