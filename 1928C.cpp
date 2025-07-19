#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int x, n;
    cin >> n >> x;
    int ans = 0;
    set<int> st;
    auto check = [&](int x) {
        if((x + 2) % 2 == 0) {
            st.insert((x + 2) / 2);
        }
    };
    for(int i = 1; i <= (n - x) / i; i++) {
        if((n - x) % i == 0) {
            check(i), check((n - x) / i);
        }
    }
    //for(int i : st) cout << i << '\n';
    for(int i = 1; i <= (n + x - 2) / i; i++) {
        if((n + x - 2) % i == 0) {
            check(i), check((n + x - 2) / i);
        }
    }
    //for(int i : st) cout << i << '\n';
    for(auto i : st) {
        bool nice = 0;
		int r = n % (2 * i - 2);
		if(r == 0) r = 2 * i - 2;
		int tmp = r;
		if(r > i) {
			r = 2 + (2 * i - 2) - r;
		}
		if(r == x) nice = 1;
		
		if(nice) {
			//cout << i << '\n';
			//if(tmp > i) cout << i << '\n';
			ans++;
		}
    }
    cout << ans << '\n';
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