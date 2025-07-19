#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	int s = sqrt(m);
	vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> heavy(n + 1), fa(n + 1), sz(n + 1, 1), dep(n + 1), top(n + 1);
	function <void(int, int)> dfs_init = [&](int u, int f) {
		dep[u] = dep[f] + 1;
		for(int v : g[u]) {
			if(v == f) continue;
			fa[v] = u;
			dfs_init(v, u);
			sz[u] += sz[v];
			if(!heavy[u] || sz[v] > sz[heavy[u]]) heavy[u] = v;
		}	
	};
	dfs_init(1, 0);
	function <void(int, int)> dfs = [&](int u, int t) {
		top[u] = t;
		if(heavy[u]) dfs(heavy[u], t);
		for(int v : g[u]) {
			if(v == fa[u] || v == heavy[u]) continue;
			dfs(v, v);
		}	
	};
	dfs(1, 1);
	auto lca = [&](int u, int v) {
		while(top[u] != top[v]) {
			if(dep[top[u]] < dep[top[v]]) v = fa[top[v]];
			else u = fa[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	};
	auto dist = [&](int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	};
	vector<int> wait;
	vector<int> dis(n + 1, -1);
	queue <int> q;
	q.push(1);
	dis[1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : g[u]) {
			if(dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		int op, u;
		cin >> op >> u;
		if(op == 1) {
			wait.push_back(u);
			if(wait.size() >= s) {
				for(int v : wait) q.push(v);
				while(!q.empty()) {
					int u = q.front();
					q.pop();
					for(int v : g[u]) {
						if(dis[v] > dis[u] + 1) {
							dis[v] = dis[u] + 1;
							q.push(v);
						}
					}
				}
				wait.clear();
			}
		}
		else {
			int ans = dis[u];
			for(int v : wait) {
				ans = min(ans, dist(u, v));
			}
			cout << ans << '\n';
		}
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