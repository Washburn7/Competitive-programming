#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
ll power(ll a, ll b, ll P) {
    a %= P;
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res % P;
}
ll inv(ll x, ll p) {
	return power(x, p - 2, p);
}
void solve() {
    ll ans = 1;
    ll n;
    int p;
    int k;
    cin >> n >> p >> k;
    for(int j = 0; j < k; j++) {
        ll x = ((power(2, n, p) - power(2, j, p)) % p + p) % p;
        ll y = ((power(2, k, p) - power(2, j, p)) % p + p) % p;
        ans = ans * x % p * x % p * inv(y, p) % p;
        cout << ans << ' ';
    }
    
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