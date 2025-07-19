#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    int B = sqrt(n) + 1;
    vector<ll> a(n + 1);
    vector<vector<ll>> sum(B + 1, vector<ll> (n + 1));
    vector<vector<ll>> pre(B + 1, vector<ll> (n + 1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= B; j++) {
            if(i - j > 0) sum[j][i] = sum[j][i - j] + 1ll * a[i] * ((i + j - 1) / j), pre[j][i] += pre[j][i - j] + a[i];
            else sum[j][i] = a[i], pre[j][i] = a[i];
        }
    }
    while(q--) {
        int s, d, k;
        cin >> s >> d >> k;
        if(d > B) {
            ll ans = 0;
            for(int i = 1; i <= k; i++) {
                ans += 1ll * a[s] * i;
                s += d;
            }
            cout << ans << ' ';
        }
        else {
            // cout << "to2 ";
            // cout << (pre[d][s + d * (k - 1)] - pre[d][s]) << "  ";
            cout << sum[d][s + d * (k - 1)] - sum[d][s] - (pre[d][s + d * (k - 1)] - pre[d][s]) * ((s + d - 1) / d - 1) + a[s] << ' ';
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