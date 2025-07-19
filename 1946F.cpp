#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
struct node {
	int l, r;
	ll v;
#define ls u << 1
#define rs u << 1 | 1
} tr[N << 2];
void pushup(int u) {
	tr[u].v = tr[ls].v + tr[rs].v;
}
void build(int u, int l, int r) {
	tr[u] = {l, r};
	if(l == r) {
		tr[u].v = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
ll query(int u, int l, int r) {
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
	int mid = tr[u].l + tr[u].r >> 1;
	ll v = 0;
	if(l <= mid) v += query(ls, l, r);
	if(r > mid) v += query(rs, l, r);
	return v;
}
void modify(int u, int x, int v) {
	if(tr[u].l == x && tr[u].r == x) tr[u].v += v;
	else {
		int mid = tr[u].l + tr[u].r >> 1;
		if(mid >= x) modify(ls, x, v);
		else modify(rs, x, v);
		pushup(u);
	}
}
void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<ll>> cnt(n + 1);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]].resize((n / a[i]) + 1);
	}
	//cout << cnt[1].size() << '\n';
	vector<int> use(n + 1), pos(n + 1);
	for(int i = n; i >= 1; i--) {
		pos[a[i]] = i;
		for(int j = 1; j * a[i] <= n; j++) {
			if(!use[j * a[i]]) continue;
			else {
				int p = j * a[i];
				for(int k = 1; k < cnt[p].size(); k++) {
					cnt[a[i]][p * k / a[i]] += cnt[p][k];
				}
			}
		}
		use[a[i]] = 1;
		cnt[a[i]][1] = 1;
	}
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < cnt[i].size(); j++) {
			int po = pos[i * j];
			modify(1, po, cnt[i][j]);
		}
	}
	vector<array<int, 3>> que(q + 1);
	vector<ll> ans(q + 1);
	
	for(int i = 1; i <= q; i++) {
		cin >> que[i][0] >> que[i][1];
		que[i][2] = i;
	}
	sort(que.begin() + 1, que.end());
	int lst = 0;
	for(auto [x, y, z] : que) {
		if(x > lst) {
			for(int i = lst + 1; i < x; i++) {
				int x = a[i];
				for(int j = 1; j < cnt[x].size(); j++) {
					int po = pos[x * j];
					modify(1, po, -cnt[x][j]);
				}
			}
			lst = x - 1;
		}
		ans[z] = query(1, x, y);
	}
	
	for(int i = 1; i <= q; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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