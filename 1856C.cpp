#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = a[n];
    auto check = [&](int p, int x) {
        auto b = a;
        b[p] = x;
        ll need = x - a[p];
        for(int i = p + 1; i <= n; i++) {
            if(i != n) {
                if(b[i] < b[i - 1] - 1) need += b[i - 1] - 1 - b[i], b[i] = b[i - 1] - 1;
                else break;
            }
            else {
                if(b[i] < b[i - 1] - 1) return 0;
            }
        }
        if(need <= k) return 1;
        else return 0;
    };
    for(int i = 1; i < n; i++) {
        int lo = a[i], hi = a[i] + k;
        while(lo < hi) {
            int mid = lo + hi + 1 >> 1;
            if(check(i, mid)) lo = mid;
            else hi = mid - 1;
        }
        // if(i == 1) {
        //     for(int j = a[i]; j <= a[i] + k; j++) cout << check(i, j) << '\n';
        // }
        //cout << i << ' ' << lo << '\n';
        ans = max(ans, lo);
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