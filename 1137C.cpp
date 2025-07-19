#include <bits/stdc++.h>

using namespace std;
using ll = long long;
inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
constexpr int N = 5e6 + 10, M = 1e5 + 10;
int dfn[N], low[N], stk[N], id[N], ins[N];
int h[N], g[N], ne[N], val[N], dep[N];
string s[M];
bool vis[100010];
int timestamp = 0, top = 0, scc_cnt = 0, idx = 0;
int n, m, d;
void add(int a, int b) {
    g[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void scc(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, ins[u] = 1;
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = g[i];
        if(!dfn[j]) {
            scc(j);
            low[u] = min(low[u], low[j]);	
        }
        else if(ins[j]) low[u] = min(low[u], dfn[j]);
    }
    if(dfn[u] == low[u]) {
        ++scc_cnt;
        int y;
        queue<int> use;
        do {
            y = stk[top--];
            ins[y] = 0;
            id[y] = scc_cnt;
            int blk = (y - 1) / d + 1;
            int rmn = (y - 1) % d + 1;
            //if(scc_cnt == 1) cout << blk << ' ' << rmn << '\n';
            if(!vis[blk] && s[blk][rmn - 1] == '1') val[scc_cnt]++, vis[blk] = 1, use.push(blk);
        } while(y != u);
        while(!use.empty()) {
            int u = use.front();
            use.pop();
            vis[u] = 0;
        }
    }
}
void solve() {
	memset(h, -1, sizeof h);
    read(n);
    read(m);
    read(d);
    vector<vector<int>> e(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        read(u);
        read(v);
        e[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) {
        for(int v : e[i]) {
            for(int j = 0; j < d; j++) {
                int idx = (i - 1) * d + j, idy = (v - 1) * d + (j + 1) % d;
                idx++, idy++;
                add(idx, idy);
            }
        }
    }
    for(int i = 1; i <= n * d; i++) {
        if(!dfn[i]) scc(i);
    }
    for(int i = 1; i <= scc_cnt; i++) h[i] = -1;
    idx = 0;
    for(int i = 1; i <= n; i++) {
        for(int v : e[i]) {
            for(int j = 0; j < d; j++) {
                int idx = (i - 1) * d + j, idy = (v - 1) * d + (j + 1) % d;
                idx++, idy++;
                if(id[idx] != id[idy]) add(id[idx], id[idy]), dep[id[idy]]++;
            }
        }
    }
    vector<int> dp(scc_cnt + 1, -1e9);
    queue<int> q;
    for(int i = 1; i <= scc_cnt; i++) if(!dep[i]) q.push(i);
    dp[id[1]] = val[id[1]];
    int mx = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        mx = max(mx, dp[u]);
        for(int i = h[u]; i != -1; i = ne[i]) {
            int v = g[i];
            dep[v]--;
            dp[v] = max(dp[v], dp[u] + val[v]);
            if(!dep[v]) q.push(v);
        }
    }
    //cout << dp[4] << ' ' << dp[3] << ' ' << dp[2] << '\n';
    cout << mx;
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
