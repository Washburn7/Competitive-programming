#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    set <pair<ll, ll>> ans;
    priority_queue<array<int, 3>> pq1, pq2;
    int n;
    cin >> n;
    vector<int> use(n + 1);
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        pq1.push({x[i], y[i], i});
        pq2.push({y[i], x[i], i});
    }
    {   
        int tim = 0, cnt = 0;
        vector<array<ll, 2>> rec; 
        while(cnt != n) {
            tim++;
            if(tim & 1) {
                bool f = 0;
                int tu;
                ll sum = 0;
                while(!pq1.empty()) {
                    auto [u, v, w] = pq1.top();
                    if(f) {
                        if(u != tu) break;
                    }
                    pq1.pop();
                    if(use[w]) continue;
                    else {
                        f = 1;
                        tu = u;
                        sum += v;
                        use[w] = 1;
                        cnt++;
                    }
                }
                rec.push_back({tu, sum});
            }
            else {
                bool f = 0;
                int tv;
                ll sum = 0;
                while(!pq2.empty()) {
                    auto [u, v, w] = pq2.top();
                    if(f) {
                        if(u != tv) break;
                    }
                    pq2.pop();
                    if(use[w]) continue;
                    else {
                        f = 1;
                        tv = u;
                        sum += v;
                        use[w] = 1;
                        cnt++;
                    }
                }
                rec.push_back({tv, sum});
            }
        }
        if(rec.size() == 1) {
            ans.insert({rec[0][0], rec[0][1]});
        }
        else {
            ll h = rec[0][0], w = rec[0][1] + rec[1][0];
            ll th = h, tw = w;
            bool nice = 1;
            for(int i = 0; i < rec.size(); i++) {
                ll x = rec[i][0], y = rec[i][1];
                if(i % 2 == 0) {
                    if(h != x) {
                        nice = 0;
                        break;
                    }
                    w -= y;
                }
                else {
                    if(h != x) {
                        nice = 0;
                        break;
                    }
                    w -= y;
                }
                swap(h, w);
                if(!h || !w) {
                    if(i != rec.size() - 1) {
                        nice = 0;
                        break;
                    }
                }
            }
            if(nice) {
                if(h && w) nice = 0;
            }
            if(nice) ans.insert({th, tw});
        }
    }
    for(int i = 1; i <= n; i++) use[i] = 0;
    while(!pq1.empty()) pq1.pop();
    while(!pq2.empty()) pq2.pop();
    for(int i = 1; i <= n; i++) {
        pq1.push({x[i], y[i], i});
        pq2.push({y[i], x[i], i});
    }
    {
        int tim = 0, cnt = 0;
        vector<array<ll, 2>> rec; 
        while(cnt != n) {
            tim++;
            if(tim % 2 == 0) {
                bool f = 0;
                int tu;
                ll sum = 0;
                while(!pq1.empty()) {
                    auto [u, v, w] = pq1.top();
                    if(f) {
                        if(u != tu) break;
                    }
                    pq1.pop();
                    if(use[w]) continue;
                    else {
                        f = 1;
                        tu = u;
                        sum += v;
                        use[w] = 1;
                        cnt++;
                    }
                }
                rec.push_back({tu, sum});
            }
            else {
                bool f = 0;
                int tv;
                ll sum = 0;
                while(!pq2.empty()) {
                    auto [u, v, w] = pq2.top();
                    if(f) {
                        if(u != tv) break;
                    }
                    pq2.pop();
                    if(use[w]) continue;
                    else {
                        f = 1;
                        tv = u;
                        sum += v;
                        use[w] = 1;
                        cnt++;
                    }
                }
                rec.push_back({tv, sum});
            }
        }
        //for(auto [x, y] : rec) cout << x << ' ' << y << '\n';
        if(rec.size() == 1) {
            ans.insert({rec[0][1], rec[0][0]});
        }
        else {
            ll h = rec[0][1] + rec[1][0], w = rec[0][0];
            //cout << h << ' ' << w << '\n';
            ll th = h, tw = w;
            bool nice = 1;
            for(int i = 0; i < rec.size(); i++) {
                ll x = rec[i][0], y = rec[i][1];
                if(i % 2 == 0) {
                    if(w != x) {
                        nice = 0;
                        break;
                    }
                    h -= y;
                }
                else {
                    if(w != x) {
                        nice = 0;
                        break;
                    }
                    h -= y;
                }
                swap(h, w);
                if(!h || !w) {
                    if(i != rec.size() - 1) {
                        nice = 0;
                        break;
                    }
                }
            }
            if(nice) {
                if(h && w) nice = 0;
            }
            if(nice) ans.insert({th, tw});
        }
    }
    cout << ans.size() << '\n';
    for(auto [u, v] : ans) cout << u << ' ' << v << '\n';
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