#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    if(n == 2) {
        cout << "1 1\n1 2\n";
    }
    else if(n == 3) {
        cout << "2 1\n2 3\n3 1\n";
    }
    else {
        cout << "1 1\n1 2\n4 2\n4 4\n";
        for(int j = 5; j <= n; j++) {
            cout << j << ' ' << j << '\n';
        }
    }
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