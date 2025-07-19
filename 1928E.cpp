#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, x, y, s;
	cin >> n >> x >> y >> s;
	if(1ll * (x % y) * n > s) cout << "NO\n";
	else {
		int rmn = s - (x % y) * n;
		vector<int> dp(s + 1, 1e8), from(s + 1);
		dp[0] = 0;
		for(int i = 1; i * (i + 1) / 2 * y <= s; i++) {
			for(int j = i * (i + 1) / 2 * y; j <= s; j++) {
				if(dp[j] > dp[j - i * (i + 1) / 2 * y] + (i + 1)) {
					dp[j] = dp[j - i * (i + 1) / 2 * y] + (i + 1);
					from[j] = i;
				}
			}
		}
//		cout << dp[3] << ' ' << from[3] << '\n';
//		cout << rmn << '\n';
		//2 2 2 2 2
		for(int i = 0; (i + 1) * x + i * (i + 1) / 2 * y - (i + 1) * (x % y) <= rmn && i + 1 <= n; i++) {
			int t = rmn - ((i + 1) * x + i * (i + 1) / 2 * y - (i + 1) * (x % y));
			//cout << i << ' ' << t << '\n';
			if(t >= 0) {
				//cout << i << '\n';
				if(i + 1 + dp[t] <= n) {
					//cout << i << '\n';
					cout << "YES\n";
					vector<int> ans(n + 1);
					for(int j = 1; j <= i + 1; j++) ans[j] = x + (j - 1) * y;
					for(int j = i + 2; j <= n; j++) {
						ans[j] = x % y;
					}
					int cur = i + 2;
					while(t != 0) {
						int u = from[t];
						//cout << u << ' ' << t << '\n';
						for(int j = 0; j <= u; j++) {
							ans[cur + j] += j * y;
						}
						cur += u + 1;
						t -= u * (u + 1) / 2 * y;
					}
					for(int j = 1; j <= n; j++) {
						cout << ans[j] << ' ';
					}
					cout << '\n';
					return ;
				}
			}
		}
		cout << "NO\n";
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
