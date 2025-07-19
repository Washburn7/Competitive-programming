#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n + 1);
    for(int i = 1; i < n; i++) {
        cin >> a[i];
    }
    ans[1] = a[1];
    for(int i = 2; i < n; i++) {
        if(a[i] > a[i - 1]) {
            ans[i + 1] = a[i];
        }
        else {
            ans[i] = a[i];
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
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