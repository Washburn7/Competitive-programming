#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int M = 5e6 + 10;
constexpr int N = 1e5 + 10;
int prime[M], phi[M], m;
bool st[M];
void get_euler(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!st[i]) {
			prime[++m] = i;
			phi[i] = i - 1;
		}
		for(int j = 1; prime[j] <= n / i; j++) {
			st[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i * prime[j]] = prime[j] * phi[i];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}
int a[N];
struct node {
	int l, r;
	ll sum;
	bool op;
	vector<int> to;
#define ls u << 1
#define rs u << 1 | 1
}tr[N << 2];
auto merge(auto x, auto y) {
	vector<int> ans(25);
	for(int i = 0; i <= 24; i++) {
		if(x[i] != y[i]) ans[i] = 1e9;
		else ans[i] = x[i];
	}
	return ans;
}
void pushup(int u) {
	tr[u].sum = tr[ls].sum + tr[rs].sum;
	tr[u].to = merge(tr[ls].to, tr[rs].to);
	tr[u].op = (tr[ls].op & tr[rs].op);
}

void build(int u, int l, int r) {
	if(l == r) {
		tr[u] = {l, r, a[l]};
		int x = a[l];
		for(int i = 0; i <= 24; i++) {
			tr[u].to.push_back(x);
			x = phi[x];
		}
	}
	else {
		tr[u] = {l, r, 0};
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r) {
	if(tr[u].l >= l && tr[u].r <= r && tr[u].l == tr[u].r && !tr[u].op) {
		tr[u].sum = phi[tr[u].sum];
		if(tr[u].sum == 1) tr[u].op = 1;
		int x = tr[u].sum;
		for(int i = 0; i <= 24; i++) {
			tr[u].to[i] = x;
			x = phi[x];
		}
	}
	else if(tr[u].op) {
		return ;
	}
	else {
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(ls, l, r);
		if(r > mid) modify(rs, l, r);
		pushup(u);
	}
}

vector<int> query(int u, int l, int r) {
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].to;                       
	int mid = tr[u].l + tr[u].r >> 1;
	vector<int> ans(25);
	if(l <= mid) ans = query(ls, l, r);
	if(r > mid) ans = merge(ans, query(ls, l, r));
	return ans;
}
void solve() {
	get_euler(M - 10);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		cout << "i:" << i << '\n';
		 int op, l, r;
		 cin >> op >> l >> r;
		 if(op == 1) {
		     modify(1, l, r);
		 }
		 else {
		     auto v = query(1, l, r);
		     int ans = 1e9;
		     for(int i = 0; i <= 24; i++) {
		         if(v[i] < 1e8) ans = min(ans, i);
		     }
		     cout << ans << '\n';
		 }
	}
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	
	int t;
	t = 1;
	
	while(t--) {
		solve();
	}
	
	return 0;
}