#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, q, a[N], x, h[21], st[21][N];
map<int, long long> m;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	h[0] = 1;
	for(int i = 1; i <= 20; i++){
		h[i] = h[i - 1] * 2;
	}
	for(int i = 0; i <= log2(n); i++){
		for(int j = 1; j <= n - h[i] + 1; j++){
			if(i == 0) st[i][j] = a[j];
			else st[i][j] = gcd(st[i - 1][j], st[i - 1][j + h[i - 1]]);
		}
	}
	auto query = [&](int l, int r) {
		int k = (int)log2(r - l + 1);
		return gcd(st[k][l], st[k][r - (1 << k) + 1]);
	};
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int l = j, r = n;
            int g = query(i, j);
			while(l < r){
				int mid = (l + r + 1) / 2;
				if(g == query(i, mid)){
					l = mid;
				}
				else r = mid - 1;
			}
			//cout << i << ' ' << j << ' ' << l << '\n';
			m[g] += l - j + 1;
			j = l;
		}
	}
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> x;
		if(m.count(x)) cout << m[x] << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}