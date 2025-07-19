#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int d[N];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> res(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            int ans = 0;
            for(int j = 1; j <= i; j++) {
                vector<int> p;
                for(int k = j; k <= n; k += i) {
                    p.push_back(a[k]);
                }
                sort(p.begin(), p.end());
                int g = 0;
                for(int k = 1; k < p.size(); k++) {
                    g = gcd(g, p[k] - p[k - 1]);
                }
                ans = gcd(ans, g);
            }
            if(ans != 1) sum++;
            //cout << i << ' ' << ans << '\n';
            // for(int j = 1; j <= ans / j; j++) {
            //     if(ans % j == 0) res[j] = 1, res[ans / j] = 1;
            // }
            //sum += d[ans] - 1;
        }
    }
    
    //for(int i = 2; i <= n; i++) sum += res[i];
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            d[j]++;
        }
    }
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}