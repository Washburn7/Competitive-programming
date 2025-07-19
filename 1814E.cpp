#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

struct Info {
    ll dp[2][2];
    Info() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                dp[i][j] = 1e18;
        }
    }
}
struct node {
    int l, r;
    Info info;
    #define ls u << 1
    #define rs u << 1 | 1
} tr[N << 2];
void pushup(int u) {
    tr[u].info = tr[ls].info + tr[rs].info;
}
void build(int u, int l, int r) {
    tr[u] = {l, r};
    if(l == r) {
        tr[u].v = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushup(u);
}
void modify(int u, int x, int v) {
    if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(mid >= x) modify(ls, x, v);
        else modify(rs, x, v);
        pushup(u);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;

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