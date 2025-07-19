#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
vector<int> z_function(string &s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r && z[i - l] < r - i + 1) {
			z[i] = z[i - l];
		} else {
			z[i] = max(0, r - i + 1);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
		}
		if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
	}
	return z;
}
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    auto z = z_function(s);
    vector<int> ans(n + 1);
    set<int> st;
    vector<vector<int>> v(n + 1);
    for(int i = 0; i < s.size(); i++) {
        if(z[i]) st.insert(i), v[z[i]].push_back(i);
        //cout << i << ' ' << z[i] << '\n';
    }
    for(int i = 0; i < s.size(); i++) {
        int len = i + 1;
        int last = len;
        for(int j : v[len - 1]) {
            st.erase(j);
        }
        // if(len == 3) {
        //     for(auto x : st) {
        //         cout << "bug : " << x << ' ' << last << ' ' << i << ' ' << len << '\n';
        //     }
        // }
        int cnt = 1;
        while(1) {
            auto pos = st.lower_bound(last);
            if(pos == st.end()) break;
            // if(len == 3) {
            //     cout << "bug1 : " << last << '\n';
            // } 
            last = *pos + len;
            cnt++;
        }
        ans[cnt] = len;
        //cout << len << ' ' << cnt << '\n';
    }

    for(int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for(int i = l; i <= r; i++) {
        cout << ans[i] << ' ';
    }

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