#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<i64, 4>> a(n + 1);
    vector<i64> sur(n + 2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i][1];
        a[i][2] = -a[i][0] - (a[i][1] - a[i][0]);
        a[i][3] = a[i][1] - a[i][0]; 
    }
    
    sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
        return x[2] < y[2];
        //else return x[3] > y[3];
    });
    for(int i = n; i >= 1; i--) {
        sur[i] = sur[i + 1];
        if(a[i][1] - a[i][0] > 0) sur[i] += a[i][1] - a[i][0];
    }
    i64 ans = 0;
    priority_queue<i64> q;
    i64 sum = 0;
    for(int i = 1; i <= n; i++) {
        if(q.size() == k) {
            ans = max(ans, sur[i] - sum);
        }
        q.push(a[i][0]);
        sum += a[i][0];
        if(q.size() > k) {
            i64 u = q.top();
            q.pop();
            sum -= u;
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