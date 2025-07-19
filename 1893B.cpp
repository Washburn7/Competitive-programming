#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(b.begin() + 1, b.end());
    vector<int> ldp(n + 1), rdp(n + 1);
    int lcur = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            ldp[1] = a[i];
            lcur++;
        }
        else {
            int lo = 0, hi = lcur;
            while(lo < hi) {
                int mid = lo + hi + 1 >> 1;
                if(ldp[mid] < a[i]) lo = mid;
                else hi = mid - 1;
            }
            ldp[lo + 1] = a[i];
            lcur = max(lcur, lo + 1);
        }
    }
    int rcur = 0;
    for(int i = n; i >= 1; i--) {
        if(i == n) {
            rdp[1] = a[i];
            rcur++;
        }
        else {
            int lo = 0, hi = rcur;
            while(lo < hi) {
                int mid = lo + hi + 1 >> 1;
                if(rdp[mid] > a[i]) lo = mid;
                else hi = mid - 1;
            }
            rdp[lo + 1] = a[i];
            rcur = max(rcur, lo + 1);
        }
    }
    //cout << lcur << ' ' << rcur << '\n';
    //for(int i = 1; i <= lcur; i++) cout << i << ' ' << ldp[i] << '\n';
    for(int i = 0; i <= m; i++) {
        int L = i, R = i + 1;
        bool nice = 1;
        if(L != 0) {
            if(b[L] < rdp[rcur]) nice = 0;
        }
        if(R != m + 1) {
            // cout << "bug:\n";
            // if(i == 0) cout << a[R] << ' ' << ldp[lcur] << '\n';
            if(b[R] > ldp[lcur]) nice = 0;
        }
        if(nice) {
            for(int j = 1; j <= L; j++) cout << b[j] << ' ';
            for(int i = 1; i <= n; i++) cout << a[i] << ' ';
            for(int j = R; j <= m; j++) cout << b[j] << ' ';
            cout << '\n';
            return ; 
        }
    }
    
    for(int i = 1; i <= m; i++) cout << b[i] << ' ';
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
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