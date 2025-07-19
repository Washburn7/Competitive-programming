#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
	cin >> n;
    vector<vector<array<int, 2>>> g(n + 1);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    double ans1 = 0, ans2 = 9e18;
    vector<int> del(n + 1), maxs(n + 1), sz(n + 1);
	function<void(int, int)> treeDivide = [&](int u, int s) {
		int root = -1;
		function<void(int, int)> center = [&](int u, int fa) {
			sz[u] = 1, maxs[u] = 0;
			for(auto [v, w] : g[u]) {
				if(del[v] || v == fa) continue;
				center(v, u);
				sz[u] += sz[v];
				maxs[u] = max(maxs[u], sz[v]);
			}
			maxs[u] = max(maxs[u], s - sz[u]);
			if(root == -1 || maxs[u] < maxs[root]) root = u; 
		};
		center(u, 0);
		del[root] = true;
        double sumds = 0, res = 0;
        vector<double> ds(n + 1);
        function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
            ds[u] = a[u] * pow(d, 0.5) * 3 / 2;
            sumds += a[u] * pow(d, 0.5) * 3 / 2;
            res += a[u] * pow(d, 1.5);
            for(auto [v, w] : g[u]) {
                if(v == fa) continue;
                dfs(v, u, d + w);
                ds[u] += ds[v];
            }
        };
        for(auto [v, w] : g[root]) {
            dfs(v, root, w);
        }
        if(res < ans2) ans1 = root, ans2 = res;
		for(auto [v, w] : g[root]) {
			if(!del[v]) {
                if(sumds - ds[v] * 2 < 0) treeDivide(v, sz[v]);
            }
		}
	};
    treeDivide(1, n);
    cout << ans1 << ' ';
    cout << fixed << setprecision(10) << ans2;
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
