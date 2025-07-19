#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int st[20][N], lg[N];
void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];
    sort(a.begin() + 1, a.end());
    
    for(int i = 0; i < 20; i++) {
        int len = (1 << i);
        for(int j = 1; j + len - 1 <= n; j++) {
            if(!i) st[i][j] = a[j][1];
            else st[i][j] = max(st[i][j - 1], st[j + len - (1 << (j - 1))][j - 1]);
        }
    }

    auto qrymx(int l, int r) {
        
    };
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