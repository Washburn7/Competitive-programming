#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int r = i;
        for(int j = i + 1; j <= n; j++) {
            if(a[j] > a[j - 1]) break;
            r = j;
        }
        cnt++;
        i = r;
    }
    cout << max(0, cnt - 2) << '\n';
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