#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1);
    vector<pair<int, int>> v(n + 1);
    set<pair<int, int>> st;
    set<int> live;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++) {
        live.insert(i);
        int hp = d[i];
        if(i - 1 > 0) hp -= a[i - 1];
        if(i + 1 <= n) hp -= a[i + 1];
        st.insert({hp, i});
        v[i] = {hp, i};
    }
    for(int i = 1; i <= n; i++) {
        int start = live.size();
        vector<int> kill;
        for(auto it = st.begin(); it != st.end();) {
            auto [x, y] = *it;
            if(x >= 0) break;
            kill.push_back(y);
            live.erase(y);
            it = st.erase(it);
        }
        vector<int> will;
        for(int j : kill) {
            auto p1 = live.upper_bound(j);
            if(p1 != live.end()) {
                will.push_back(*p1);
            }
            auto p2 = live.lower_bound(j);
            if(p2 != live.begin()) {
                --p2;
                will.push_back(*p2);
            }
        }
        sort(will.begin(), will.end());
        will.erase(unique(will.begin(), will.end()), will.end());
        for(int j : will) {
            st.erase(v[j]);
            int hp = d[j];
            auto p1 = live.upper_bound(j);
            if(p1 != live.end()) {
                hp -= a[*p1];
            }
            auto p2 = live.lower_bound(j);
            if(p2 != live.begin()) {
                --p2;
                hp -= a[*p2];
            }
            v[j].first = hp;
            st.insert(v[j]);
        }
        // cout << "set:\n";
        // for(auto [u, v] : st) {
        //     cout << "bug: " << u << ' ' << v << '\n';
        // }
        cout << start - live.size() << ' ';
    }
    cout << '\n';
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