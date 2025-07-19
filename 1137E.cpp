#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 3e5 + 10;
pair<ll, ll> stk[N];
void solve() {
    int n, m;
    cin >> n >> m;
    ll pos = n, sumb = 0, sums = 0;
    auto get = [&](pair<ll, ll> x) {
        return sumb + sums * (x.first - 1) - x.second;
    };
    auto check = [&](pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z) {
        if((get(y) - get(z)) * (y.first - x.first) >= (get(x) - get(y)) * (z.first - y.first)) return 1;
        else return 0;
    };
    int r = 0;
    int T = 0;
    stk[r = 1] = {1, 0};
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            ll k;
            cin >> k;
            pos += k;
            stk[r = 1] = {1, 0};
            sumb = sums = 0;
        }
        else if(op == 2) {
            ll k;
            cin >> k;
            pair<ll, ll> cur = {pos + 1, sumb + sums * pos};
            stk[++r] = cur;
            if(get(stk[r]) >= get(stk[r - 1])) r--;
            while(r >= 3 && check(stk[r - 2], stk[r - 1], stk[r])) stk[r - 1] = stk[r], r--;
            pos += k;
        }
        else {
            ll b, s;
            cin >> b >> s;
            sumb += b;
            sums += s;
            while(r >= 2 && get(stk[r]) >= get(stk[r - 1])) r--;
        }
        cout << stk[r].first << ' ' << get(stk[r]) << '\n';
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