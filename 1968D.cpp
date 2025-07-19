#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> p1, p2;
    int c1 = pb, c2 = ps;
    vector<int> v1(n + 1), v2(n + 1);

    while(!v1[c1]) {
        p1.push_back(c1);
        v1[c1] = 1;
        c1 = p[c1];
    }
    while(!v2[c2]) {
        p2.push_back(c2);
        v2[c2] = 1;
        c2 = p[c2];
    }

    i64 res1 = 0, res2 = 0;

    auto get = [&](auto v, auto &res) {
        i64 mx = 0, sum = 0;
        for(int i = 0; i < v.size(); i++) {
            sum += a[v[i]];
            mx = max(mx, 1ll * a[v[i]]);
            //cout << i << ' ' << v[i] << '\n';
            if(i + 1 <= k) {
                if(sum + (k - i - 1) * mx > res) res = sum + (k - i - 1) * mx;
            }
        }
    };

    get(p1, res1), get(p2, res2);

    //cout << res1 << ' ' << res2 << '\n';
    if(res1 > res2) cout << "Bodya\n";
    else if(res1 < res2) cout << "Sasha\n";
    else cout << "Draw\n"; 
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