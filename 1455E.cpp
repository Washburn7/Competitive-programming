#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int a[5];
void solve() {
    vector<array<int, 2>> p(5);
    for(int i = 1; i <= 4; i++) cin >> p[i][0] >> p[i][1], a[i] = i;
    i64 ans = LLONG_MAX;

    do {
        vector<array<int, 2>> cand(5);
        for(int i = 1; i <= 4; i++) cand[i] = p[a[i]];
        i64 res = 0;
        res += abs(cand[1][1] - cand[3][1]) + abs(cand[2][1] - cand[4][1]);
        res += abs(cand[1][0] - cand[2][0]) + abs(cand[3][0] - cand[4][0]);
        i64 Lx = min(cand[1][0], cand[2][0]), Rx = max(cand[3][0], cand[4][0]);
        i64 Uy = max(cand[1][1], cand[3][1]), Dy = min(cand[2][1], cand[4][1]);
        i64 lenx = Rx - Lx, leny = Uy - Dy;
        if(lenx >= 0 && leny >= 0) {
            res += 2 * max(0, );
        }
        ans = min(res, ans);
    } while(next_permutation(a + 1, a + 1 + 4));

    cout << ans;
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