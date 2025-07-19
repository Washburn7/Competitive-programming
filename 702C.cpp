#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

ll a[N], b[N];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + 1 + m);
    auto check = [&](ll mid) {
        for(int i = 1; i <= n; i++) {
            int pos = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            bool ok = 0;
            if(pos >= 1 && pos <= m) {
                if(abs(b[pos] - a[i]) <= mid) ok = 1;
            }
            pos--;
            if(pos >= 1 && pos <= m) {
                if(abs(b[pos] - a[i]) <= mid) ok = 1;
            }
            if(!ok) return 0;
        }
        return 1;
    };
    ll lo = 0, hi = 2e9;
    while(lo < hi) {
        ll mid = lo + hi >> 1;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
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