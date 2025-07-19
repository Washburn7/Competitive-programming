#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int n;

struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> g;
    vector<vector<int>> c;//存每一条链
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
        p.assign(n + 1, {});
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
        c[top[u]].push_back(u);
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
int query(int u) {
    cout << "d " << u;
    int x;
    cin >> x;
    return x;
}
int nxt(int u) {
    cout << "s " << u;
    int x;
    cin >> x;
    return x;
}
void solve() {
    cin >> n;
    HLD hld(n);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    hld.init();
    hld.g = g;
    hld.work();
    int now = 1;
    int DEP = query(1) + 1;
    while(1) {
        int end = hld.p[top[now]].back();
        int d1 = DEP - hld.dep[now], d2 = query(end);
        if(d1 + d2 == hld.dep[end] - hld.dep[now]) {
            cout << '!' << hld.p[top[now]][d1];
            break;
        }
        else {
            // x + x + (d2 - d1) = dep[end] - dep[now]
            //x = (dep[end] - dep[now] - (d2 - d1)) / 2;
            int x = (hld.dep[end] - hld.del[now] - (d2 - d1)) / 2;
            now = hld.p[top[now]][x];
            now = nxt(now);
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