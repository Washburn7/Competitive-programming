#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int n, a[N];
vector<int> g[N];
struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> g;
    //vector<vector<int>> c;//存每一条链
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n + 1);
        top.resize(n + 1);
        dep.resize(n + 1);
        parent.resize(n + 1);
        in.resize(n + 1);
        out.resize(n + 1);
        seq.resize(n + 1);
        cur = 0;
        g.assign(n + 1, {});
        //c.assign(n + 1, {});
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void work(int root = 1) {
        top[root] = root;
        dep[root] = 1;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            g[u].erase(find(g[u].begin(), g[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : g[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[g[u][0]]) {
                swap(v, g[u][0]);
            }
        }
    }
    void dfs2(int u) {
        //c[top[u]].push_back(u); 速度会慢很多慎用
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : g[u]) {
            top[v] = v == g[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = upper_bound(g[u].begin(), g[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};
struct Node {
    Node *l = NULL;
    Node *r = NULL;
    i64 hash = 0;
} tr[N << 5];
int tot = 0;
Node *null = &tr[0];
Node *newNode() {
    return &tr[++tot];
}
const int B = 114514;
const i64 P = i64(6e17) + 7;
i64 pw[N];
void add(Node *&t, int l, int r, int x) {
    t = new Node {*t};
    t->hash = (t->hash + pw[x]) % P;
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    if (x <= m) {
        add(t->l, l, m, x);
    } else {
        add(t->r, m + 1, r, x);
    }
}
vector<int> ans;
int u1, v1, u2, v2, k;
int l1, l2;
int al1, al2;
void find(int l, int r, Node *u1, Node *v1, Node *l1, Node *u2, Node *v2, Node *l2) {
    if(k == 0) return ;
    i64 hash1 = (((u1->hash + v1->hash - 2 * l1->hash) % P + P) % P + (l <= al1 && al1 <= r ? pw[al1] : 0)) % P;
    i64 hash2 = (((u2->hash + v2->hash - 2 * l2->hash) % P + P) % P + (l <= al2 && al2 <= r ? pw[al2] : 0)) % P;
    if(hash1 == hash2) return ;
    if(l == r) {
        ans.push_back(l);
        k--;
        return ;
    }
    int m = (l + r) / 2;
    find(l, m, u1->l, v1->l, l1->l, u2->l, v2->l, l2->l);
    find(m + 1, r, u1->r, v1->r, l1->r, u2->r, v2->r, l2->r);
}
void solve() {
    null->l = null->r = null;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    HLD hld(n);
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = (__int128)pw[i - 1] * B % P;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        hld.addEdge(u, v);
    }
    hld.work();

    vector<Node *> node(n + 1, null);
    function<void(int, int)> dfs = [&](int u, int fa) {
        add(node[u], 1, N - 1, a[u]);
        for(int v : g[u]) {
            if(v == fa) continue;
            node[v] = node[u];
            dfs(v, u);
        }
    };

    dfs(1, 0);
    int q;
    cin >> q;

    while(q--) {
        cin >> u1 >> v1 >> u2 >> v2 >> k;
        l1 = hld.lca(u1, v1), l2 = hld.lca(u2, v2);
        al1 = a[l1], al2 = a[l2];
        find(1, N - 1, node[u1], node[v1], node[l1], node[u2], node[v2], node[l2]);
        cout << ans.size() << " ";
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
        ans.clear();
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