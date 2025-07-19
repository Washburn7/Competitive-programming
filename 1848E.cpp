#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e6 + 10;
ll cnt[N];
int p[N], minp[N], pcnt;
void get_prime(int n) {
    for(int i = 2; i <= n; i++) {
        if(!minp[i]) {
            minp[i] = i;
            p[++pcnt] = i;
        }
        for(int j = 1; p[j] <= n / i && j <= pcnt; j++) {
            minp[i * p[j]] = p[j];
            if(i % p[j] == 0) break;
        }
    }
}
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
ll inv(ll x, ll P) {
    if(x % P == 0) return 0;
	return power(x, P - 2, P);
}
void solve() {
    ll x;
    int q, m;
    cin >> x >> q >> m;
    get_prime(N - 1);
    ll ans = 1;
    for(int i = 2; i * i <= x; i++) {
        ll y = 0;
        while(x % i == 0) {
            x /= i;
            y++;
        }
        if(i == 2) continue;
        cnt[i] = y;
        ans = ans * (y + 1) % m;
    }
    if(x > 2) cnt[x]++, ans = ans * 2 % m;
    //cout << "init : " << ans << '\n';
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        int num = x;
        while(num != 1) {
            int y = minp[num], c = 0;
            while(num % y == 0) {
                num /= y;
                //cout << i << ' ' << y << '\n';
                c++;
            }
            if(y != 2) {
                ans = ans * inv(cnt[y] + 1, m) % m;
                cnt[y] += c;
                ans = ans * (cnt[y] + 1) % m;
            }
        }
        cout << ans << '\n';
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