// LUOGU_RID: 111314277
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	cin >> n;
	vector<int> power(n + 1);
	for(int i = 1; i <= n; i++) cin >> power[i];
	int s = 400;
	vector<int> trans(n + 1), jump(n + 1);
	auto block = [&](int x) {
		return (x + s - 1) / s;
	};
	for(int i = n; i >= 1; i--) {
		if(i + power[i] > n) trans[i] = i;
        else if(block(i + power[i]) == block(i)) trans[i] = trans[i + power[i]], jump[i] = jump[i + power[i]] + 1;
        else trans[i] = i;
	}
    cin >> m;
	while(m--) {
		int op;
		cin >> op;
		if(op == 2) {
			int a, b;
			cin >> a >> b;
            a++;
			power[a] = b;
			for(int i = a; block(i) == block(a); i--) {
                jump[i] = 0;
				if(i + power[i] > n) trans[i] = i;
                else if(block(i + power[i]) == block(i)) trans[i] = trans[i + power[i]], jump[i] = jump[i + power[i]] + 1;
                else trans[i] = i;
			}
		}
		else {
			int a;
			cin >> a;
            a++;
			int ans = 0;
			while(1) {
				if(a + power[a] > n) {
                    ans++;
                    break;
                }
				else if(a == trans[a]) ans++, a += power[a];
				else ans += jump[a], a = trans[a];
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