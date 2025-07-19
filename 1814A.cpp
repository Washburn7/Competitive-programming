#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    ll n, k;
    cin >> n >> k;
    if(n % 2 == 0) cout << "YES\n";
    else {
        if(k % 2 == 0) cout << "NO\n";
        else {
            if(n >= k) cout << "YES\n";
            else cout << "NO\n";
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