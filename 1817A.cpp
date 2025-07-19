#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int n, q, a[N];
vector<>
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int )
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(r - l + 1 <= 10) {
            int ans = 0;
            for(int i = l; i <= r; i++) {
                for(int j = i; j <= r; j++) {
                    bool nice = 1;
                    for(int k = i; k + 2 <= r; k++) {
                        if(a[k] >= a[k + 1] && a[k + 1] >= a[k + 2]) {
                            nice = 0;
                            break;
                        }
                    }
                    if(nice) {
                        ans = max(ans, j - i + 1);
                    }
                }
            }
        }
        else {

        }
    }
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