#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
constexpr int P = 1e9 + 7;
ll power(ll a, ll b) {
	a %= P;
	ll res = 1 % P;
	while (b) {
		if (b & 1) {
			res = res * a % P;
		}
		a = a * a % P;
		b >>= 1;
	}
	return res;
}
vector<ll> fact, inv_fact, inv;
ll c(int n, int m) {
    if(n < m || m < 0) return 0;
	return fact[n] * inv_fact[m] % P * inv_fact[n - m] % P;
}
void init(int n) {
	fact.resize(n + 1);
	inv_fact.resize(n + 1);
	inv.resize(n + 1);
	fact[0] = 1;
	auto _inv = [&](ll x) {
		return power(x, P - 2);
	};
	for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % P;
	for(int i = 2; i <= n; i++) inv[i] = (1ll * P - P / i) * inv[P % i] % P;
	inv_fact[n] = _inv(fact[n]);
	for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % P;
}

int pos[5010][5010], rk[5010][5010], a[N];
void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            rk[j][i] = rk[j][i - 1];
        }
        rk[a[i]][i]++;
        pos[a[i]][rk[a[i]][i]] = i;
    }
    vector<vector<array<ll, 2>>> g(n + 1);
    vector<int> d(n + 1);
    for(int i = 0; i <= n; i++) {
        if(i != 0 && !d[i]) continue;
        for(int j = i + 1; j <= n; j++) {
            int rank = rk[a[j]][i];
            int rank1 = rk[a[j]][j];
            if(rank1 - rank >= k) {
                d[j]++;
                ll cnt = c(rank1 - rank - 1, k - 1);
                g[i].push_back({j, cnt});
            }
        }
    }
    queue<int> q;
    vector<ll> dp(n + 1);
    vector<int> dis(n + 1);
    q.push(0);
    dp[0] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        //cout << u << ' ' << dis[u] << ' ' << dp[u] << '\n';
        for(auto [v, w] : g[u]) {
            //cout << u << ' ' << v << ' ' << w << '\n';
            d[v]--;
            if(dis[u] + 1 > dis[v]) {
                dis[v] = dis[u] + 1;
                dp[v] = dp[u] * w % P;
            }
            else if(dis[u] + 1 == dis[v]) {
                dp[v] = (dp[v] + dp[u] * w % P) % P;
            }
            if(!d[v]) {
                q.push(v);
            }
        }
    }
    int mx = *max_element(dis.begin(), dis.end());
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dis[i] == mx) ans = (ans + dp[i]) % P;
    }
    if(!mx) cout << 1 << "\n";
    else cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pos[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(N - 10);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}