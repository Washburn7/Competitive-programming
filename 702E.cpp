#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector<int> adj(n);
	vector<ll> w(n);
	for(int i = 0; i < n; i++) {
		cin >> adj[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> w[i];
	}
	vector<vector<int>> mn(n, vector<int> (41)), fa(n, vector<int> (41));
	vector<vector<ll>> sum(n, vector<ll> (41));
	for(int i = 0; i <= 40; i++) {
		for(int j = 0; j < n; j++) {
			if(!i) mn[j][i] = w[j], sum[j][i] = w[j], fa[j][i] = adj[j];
			else mn[j][i] = min(mn[j][i - 1], mn[fa[j][i - 1]][i - 1]), sum[j][i] = sum[j][i - 1] + sum[fa[j][i - 1]][i - 1], fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
	for(int i = 0; i < n; i++) {
		int mnans = 1e9, cur = i;
		ll rmn = k, sumans = 0;
		for(int j = 40; j >= 0; j--) {
			if(rmn >= (1ll << j)) {
				mnans = min(mnans, mn[cur][j]);
				sumans = sumans + sum[cur][j];
				cur = fa[cur][j];
				rmn -= (1ll << j);
			}
		}
		
		cout << sumans << ' ' << mnans << '\n';
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