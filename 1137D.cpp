#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int from[N];
int get() {
    int x;
    cin >> x;
    for(int i = 1; i <= x; i++) {
        string s;
        cin >> s;
        for(char c : s) from[c - '0'] = i;
    }
	return x;
}

void solve() {
    for(int i = 1; i; i++) {
        if(i % 2 == 0) {
            cout << "next 0 1" << endl;
			if(get() == 2) break;
        }
        else {
            cout << "next 1" << endl;
			get();
        }
    }
    while(1) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        if(get() == 1) break;
    }
    cout << "done" << endl;
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
