#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 3e6 + 10;
int a[N], b[N];
void solve() {
    int n, k;
    cin >> n;
    k = log2(n);
    bool postive = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]) postive = 1;
    }
    if(!postive) {
        cout << 0;
        return ; 
    }
    int ans = 0;
    for(int i = k - 1; i >= 0; i--) {
        bool nice = 1;
        for(int j = 0; j < n; j++) {
            int res = (a[j] ^ a[(j + (1 << i)) % n]);
            if(res) nice = 0;
        }
        if(!nice) {
            ans += (1 << i);
            for(int j = 0; j < n; j++) {
                b[j] = (a[j] ^ a[(j + (1 << i)) % n]);
            }
            for(int j = 0; j < n; j++) {
                a[j] = b[j];
            }
        }
    }
    cout << ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;

    while(t--) {
        solve();
    }

    return 0;
}