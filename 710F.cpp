// LUOGU_RID: 163638373
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 3e5 + 10;
int n;
struct Hash {
	int Base, P;//常用模数1e9+7，998244353，常用base 131，13331
	vector<int> power, sum;
	void init(int base, int p, string &s) {
        //s需要从1开始
		power.resize(s.size()), sum.resize(s.size());
		P = p, Base = base, power[0] = 1;
		for(int i = 1; i < s.size(); i++) {
			power[i] = 1ll * power[i - 1] * Base % P;
			sum[i] = (1ll * sum[i - 1] * Base + s[i]) % P;
		}
	}
	int gethash(int l, int r) {
		return (sum[r] - 1ll * sum[l - 1] * power[r - l + 1] % P + P) % P;
	}
};
bool vis[N];
void solve() {
	cin >> n;
    
    srand(114514);
    int P1 = rand() % (int)1e6 + 114514, P2 = rand() % (int)1e6 + 114514;
	vector<map<array<int, 2>, int>> cnt(300001);
	vector<int> length;
	for(int i = 1; i <= n; i++) {
		int op;
		string s;
		cin >> op >> s;
		int len = (int)s.size();
		s = ' ' + s;
		if(op == 1) {
			if(!vis[len]) vis[len] = 1, length.push_back(len);
			Hash h1, h2;
			h1.init(131, P1, s);
			h2.init(13331, P2, s);
			cnt[len][{h1.gethash(1, len), h2.gethash(1, len)}]++;
		}
		else if(op == 2) {
			Hash h1, h2;
			h1.init(131, P1, s);
			h2.init(13331, P2, s);
			cnt[len][{h1.gethash(1, len), h2.gethash(1, len)}]--;
		}
		else {
			Hash h1, h2;
			h1.init(131, P1, s);
			h2.init(13331, P2, s);
			i64 ans = 0;
			for(auto x : length) {
				for(int i = 1; i + x - 1 < s.size(); i++) {
					int u = h1.gethash(i, i + x - 1), v = h2.gethash(i, i + x - 1);
					if(cnt[x].contains({u, v})) {
						ans += cnt[x][{u, v}];
					}
				}
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	int t;
	t = 1;
	
	while(t--) {
		solve();
	}
	
	return 0;
}