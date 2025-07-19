#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int a[N];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] - a[i - 1] == 1) {
            cnt++;
        }
        else {
            break;
        }
    }
    if(cnt & 1) {
        if(cnt == n) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else {
        if(cnt == n) cout << "Bob\n";
        else cout << "Alice\n";
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