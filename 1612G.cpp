#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 3e6 + 10;
constexpr int P = 1e9 + 7;
ll d[N];
ll f[N];
ll s(ll l, ll r) {
    int len = r - l + 1;
    return (len * l % P + len * (len - 1) / 2 % P) % P;
}
void solve() {
    int m;
    cin >> m;
    vector<int> c(m + 1);
    ll sum = 0;
    for(int i = 1; i <= m; i++) cin >> c[i], sum += c[i];
    const int B = 1e6;
    f[0] = 1;
    for(int i = 1; i <= B; i++) f[i] = f[i - 1] * i % P;
    for(int i = 1; i <= m; i++) {
        d[c[i] - 1 + B]++;
        if(1 - c[i] + B - 2 >= 0) d[1 - c[i] + B - 2]--;
    }
    ll ans1 = 0, ans2 = 1;
    for(int i = 2e6; i >= 0; i--) {
        d[i] += d[i + 2];
        ans1 = (ans1 + ((i - B) % P + P) % P * s(sum - d[i] + 1, sum) % P) % P;
        sum -= d[i];
        ans2 = ans2 * f[d[i]] % P;
    }
    cout << ans1 << " " << ans2;
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