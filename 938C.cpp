#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10, M = 1e6 + 10;
int d[M];
void get(int x) {
    return d[x];
}
struct node {
	int l, r;
	ll sum;
	#define ls u << 1
	#define rs u << 1 | 1
}tr[N << 2];
void pushup(int u) {
	tr[u].sum = tr[ls].sum + tr[rs].sum;
    tr[u].op = (tr[ls].op & tr[rs].op);
}
void build(int u, int l, int r, vector<int> &a) {
	if(l == r) tr[u] = {l, r, a[l]};
	else {
		tr[u] = {l, r, 0};
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r) {
	if(tr[u].l >= l && tr[u].r <= r && tr[u].l == tr[u].r && !tr[u].op) {
        tr[u].sum = get(tr[u].sum);
        if(tr[u].sum <= 2) tr[u].op = 1;
    }
	else {
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(ls, l, r);
		if(r > mid) modify(rs, l, r);
		pushup(u);
	}
}
ll query(int u, int l, int r) {
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
	if(l <= mid) sum = sum + query(ls, l, r);
	if(r > mid) sum = sum + query(rs, l, r);
	return sum;
}
void solve() {
    for(int i = 1; i < M; i++) {
        for(int j = i; j < M; j += i) {
            d[j]++;
        }
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n, a);
    for(int i = 1; i <= m; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            modify(1, l, r);
        }
        else {
            cout << query(1, l, r) << '\n';
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