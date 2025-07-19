#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> l(n + 1), r(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        if(i == 1 || a[i + 1] - a[i] < a[i] - a[i - 1]) {
            l[i] = a[i + 1] - a[i] - 1;
        }
        l[i] += l[i - 1];
    }
    for(int i = n; i >= 2; i--) {
        if(i == n || a[i] - a[i - 1] < a[i + 1] - a[i]) {
            r[i] = a[i] - a[i - 1] - 1;
        }
        r[i] += r[i + 1];
    }
    int m;
    cin >> m;
    while(m--) {
        int x, y;
        cin >> x >> y;
        if(x < y) {
            cout << a[y] - a[x] - l[y - 1] + l[x - 1] << '\n';
        }
        else {
            cout << a[x] - a[y] - r[y + 1] + r[x + 1] << '\n'; 
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