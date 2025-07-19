#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<ll> s(n + 1);
    vector<int> l(n + 2), r(n + 2);
    r[n + 1] = n + 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1) l[i] = i;
        else {
            if(a[i] == a[i - 1]) {
                l[i] = l[i - 1];
            }
            else {
                l[i] = i;
            }
        }
    }
    for(int i = n; i >= 1; i--) {
        if(i == n) r[i] = i;
        else {
            if(a[i] == a[i + 1]) {
                r[i] = r[i + 1];
            }
            else {
                r[i] = i;
            }
        }
    }
    auto getl = [&](int i) {
        int lo = 0, hi;
        if(l[i - 1] == i - 1) hi = i - 1;
        else hi = l[i - 1] - 1;
        //cout << "newbug  " << i << ' ' << lo << ' ' << hi << '\n';
        while(lo < hi) {
            int mid = lo + hi + 1 >> 1;
            // if(i == 3) {
            //     //cout << "newbug  "<< mid << ' ' << s[i] - s[mid - 1] << '\n';
            // }
            if(s[i - 1] - s[mid - 1] > a[i]) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }
        if(lo == 0) lo = -1;
        return lo;
    };
    auto getr = [&](int i) {
        int lo, hi = n + 1;
        if(r[i + 1] == i + 1) lo = i + 1;
        else lo = r[i + 1] + 1;
        //cout << "newbug  " << i << ' ' << lo << ' ' << hi << '\n';
        while(lo < hi) {
            int mid = lo + hi >> 1;
            if(s[mid] - s[i] > a[i]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        if(hi == n + 1) hi = -1;
        return hi;
    };
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] > a[i] || a[i + 1] > a[i]) {
            cout << 1 << ' ';
            continue;
        }
        int L = getl(i), R = getr(i);
        //cout << "bug  " << i << ' ' << L << ' ' << R << '\n';
        if(L == -1 && R == -1) {
            cout << -1 << ' ';
            continue;
        }
        
        int ans = 1e9;
        if(L != -1) {
            ans = min(ans, i - L);
        }
        if(R != -1) {
            ans = min(ans, R - i);
        }
        cout << ans << ' ';
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