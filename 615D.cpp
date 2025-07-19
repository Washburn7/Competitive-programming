#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
const int P = 1e9 + 7, P1 = 1e9 + 6;
int m;
i64 cnt[N];
i64 power(i64 a, i64 b) {
    a %= P;
	i64 res = 1;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res % P;
}
i64 power1(i64 a, i64 b) {
    a %= P1;
	i64 res = 1;
	while (b) {
		if (b & 1) res = res * a % P1;
		a = a * a % P1;
		b >>= 1;
	}
	return res % P1;
}
i64 inv(i64 x) {
    return power1(x, P1 - 2);
}
i64 pw[N];
i64 pre[N], suf[N];
void solve() {
    cin >> m;
    i64 sum = 0;
    int mx = 0;
    pw[0] = 1;
    i64 s = 1;
    for(int i = 1; i <= m; i++) {
        pw[i] = pw[i - 1] * 2 % P;
        int x;
        cin >> x;
        mx = max(mx, x);
        cnt[x]++;
        sum++;
    }
    pre[0] = 1;
    for(int i = 1; i <= mx; i++) {
        pre[i] = pre[i - 1] * (cnt[i] + 1) % P1;
    }
    suf[mx + 1] = 1;
    for(int i = mx; i >= 0; i--) {
        suf[i] = suf[i + 1] * (cnt[i] + 1) % P1;
    }
    for(int i = 2; i <= mx; i++) {
        s = s * (cnt[i] + 1) % P1;
    }
    i64 ans = 1;
    for(int i = 2; i <= mx; i++) {
        i64 r = 1;
        i64 s = pre[i - 1] * suf[i + 1] % P1;
        for(int j = 1; j <= cnt[i]; j++) {
            r = r * i % P;
            ans = ans * (power(r, s) % P) % P;
        }
        //s = s * (cnt[i] + 1) % P1;
    }
    cout << ans;
    //1 2 3 4 6 12
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