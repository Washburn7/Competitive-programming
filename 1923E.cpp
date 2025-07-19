#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;

    while(t--) {
        int n;
		cin >> n;
		ll ans = 0;
		vector<vector<int>> g(n + 1);
		vector<int> c(n + 1);
		for(int i = 1; i <= n; i++) {
			cin >> c[i];
		}
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<map<int, int>> cnt(n + 1);
		function<void(int, int)> dfs = [&](int u, int fa) {
			cnt[u][c[u]]++;
			for(int v : g[u]) {
				if(v == fa) {
					continue;
				}
				dfs(v, u);
				if(cnt[v].contains(c[u])) {
					ans += cnt[v][c[u]];
					cnt[v].erase(c[u]);
				}
				if(cnt[v].size() > cnt[u].size()) {
					swap(cnt[v], cnt[u]);
				}
				for(auto [x, y] : cnt[v]) {
					if(cnt[u].contains(x)) {
						ans += 1ll * y * cnt[u][x];
					}
					cnt[u][x] += y;
				}
			}
		};
		dfs(1, 0);
		cout << ans << '\n';
    }
	
    return 0;
}