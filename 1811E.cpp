#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    ll x;
    cin >> x;
    vector<int> d;
    while(x) {
        d.push_back(x % 9);
        x /= 9;
    }
    reverse(d.begin(), d.end());
    for(auto i : d) {
        if(i >= 4) cout << i + 1;
        else cout << i;
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