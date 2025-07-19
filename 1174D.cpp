#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, x;
    cin >> n >> x;
    n = (1 << n);
    set<int> ban;
    vector<int> no(n + 1);
    for(int i = 1; i < n; i++) {
        no[i] = (x ^ i);
    }
    vector<int> ans;
    ans.push_back(0);
    int lst = 0;
    for(int i = 1; i < n; i++) {
        if(i == x) continue;
        if(ban.find(i) == ban.end()) {
            int p = (lst ^ i);
            ans.push_back(p);
            ban.insert(no[i]);
            lst = i;
        }
    }
    cout << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i] << ' ';
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