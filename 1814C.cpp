#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<array<int, 2>> a;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end(), greater());
    vector<int> x, y;
    int cx = s1, cy = s2;
    for(auto [u, v] : a) {
        if(cx <= cy) x.push_back(v), cx += s1;
        else y.push_back(v), cy += s2;
    }
    cout << x.size() << ' ';
    for(auto i : x) cout << i << ' ';
    cout << '\n';
    cout << y.size() << ' ';
    for(auto i : y) cout << i << ' ';
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