#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), cnt(n + 1);
    vector<ll> sum(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        cnt[i] = cnt[i - 1];
        if(a[i] == 1) cnt[i] += 1;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << "NO\n";
            continue;
        }
        ll s1 = cnt[r] - cnt[l - 1], s2 = (sum[r] - sum[l - 1] - (r - l + 1));
        if(s2 >= s1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
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