#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int n, a[N], b[N], c[N];
void cal(int l, int r) {
	if(l >= r) return ;
	while(1) {
		bool nice = 0;
		for(int i = l + 1; i <= r; i++) {
			c[i] -= c[i - 1];
			if(c[i] <= 0) {
				cal(l, i - 1);
				cal(i + 1, r);
				nice = 1;
				break;
			}
		}
		if(nice) {
			break;
		}
	}
	
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cur = 1;
	int pos;
	while(1) {
		int last = (cur - 1 + n) % n;
		a[cur] -= a[last];
		if(a[cur] <= 0) {
			pos = cur;
			break;
		}
		cur = (cur + 1) % n;
	}
	//cout << pos << '\n';
	cur = 0;
	for(int i = pos; i < n; i++) {
		c[cur] = a[i];
		b[cur++] = i;
	}
	for(int i = 0; i < pos; i++) {
		c[cur] = a[i];
		b[cur++] = i;
	}
	cal(1, n - 1);
	set<int> st;
	for(int i = 0; i < n; i++) {
		if(c[i] > 0) {
			st.insert(b[i]);
		}
	}
	cout << st.size() << '\n';
	for(auto i : st) cout << i + 1 << ' ';
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