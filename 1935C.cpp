#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin() + 1, a.end(), 
        [&](auto x, auto y) {
            return x.second < y.second;
        });
    
    int ans = 0;
    //for(int i = 1; i <= n; i++) cout << i << ' ' << a[i].first << ' ' << a[i].second << '\n';
    for(int i = 1; i <= n; i++) {
        if(a[i].first <= l) {
            ans = max(ans, 1);
        }
        ll now = a[i].first - a[i].second;
        priority_queue<int> q;
        for(int j = i + 1; j <= n; j++) {
            now += a[j].second;
            if(j - 1 != i) now -= a[j - 1].second;
            if(now + a[j].first <= l) {
                q.push(a[j].first);
                now += a[j].first;
            }
            else {
                if(!q.empty() && a[j].first < q.top()) {
                    now -= q.top();
                    q.pop();
                    q.push(a[j].first);
                    now += a[j].first;
                }
            }
            //cout << i << ' ' << j << ' ' << now << ' ' << q.size() << '\n';
            if(now <= l) {
                ans = max(ans, (int)q.size() + 1);
                //cout << i << ' ' << j << ' ' << q.size() << '\n';
            }
        }
    }

    cout << ans << '\n';
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