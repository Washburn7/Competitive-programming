#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;
int n;
ll a[N], d[N];

void solve() {
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1; i <= n; i++) cin >> d[i];
    vector<vector<array<ll, 2>>> g(n + 1);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
    for(int i = 1; i <= n; i++) {
        int l = max(i - d[i], 1ll);
        g[l].push_back({a[i], i + d[i]});
    }
    auto check = [&](ll m) {
        while(!q.empty()) {
            q.pop();
        }
        // for(int i = 1; i <= n; i++) {
        //     int l = max(i - d[i], 1ll);
        //     //g[l].push_back({a[i], i + d[i]});
        //     //q.push({l, i + d[i], a[i]});
        // }
        
        bool f = 1;
        for(int i = 1; i <= n; i++) {
            for(auto [x, y] : g[i]) {
                //cout << i << ' ' << y << ' ' << x << '\n';
                q.push({y, x});
            }
            ll need = m;
            while(!q.empty()) {
                auto [x, y] = q.top();
                q.pop();
                //cout << i << ' ' << x << ' ' << y << '\n';
                if(x < i && y == 0) {
                    continue;
                } 
                else if(x < i && y) {
                    return 0;
                }
                ll mn = min(need, y);
                need -= mn;
                y -= mn;
                if(y) {
                    q.push({x, y});
                    break;
                }
            }
            //cout << i << ' ' << need << '\n';
        }
        while(!q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            if(y) f = 0;
        }
        return (int)f;
    };

    //for(int i = 0; i <= 20; i++) cout << i << ' ' << check(i) << '\n';

    ll lo = 0, hi = sum;
    while(lo < hi) {
        ll m = lo + hi >> 1;
        if(check(m)) hi = m;
        else lo = m + 1;
    }
    cout << lo;
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