#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<array<int, 4>> a(m + 1);
    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        a[i][0] = l, a[i][1] = r;
        a[i][2] = (l + r) / 2, a[i][3] = (l + r) % 2;
    }

    sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
        if(x[2] == y[2]) return x[3] < y[3];
        else return x[2] < y[2];
    });

    vector sum(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        int r = min(n, i + k - 1);
        for(int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j - 1];
            sum[i][j] += max(0, min(r, a[j][1]) - max(i, a[j][0]) + 1);
        }
    }

    if(k == n) {
        cout << sum[1][m] << '\n';
        return ;
    }

    // for(int i = 1; i <= m; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "----\n";
    int ans = 0;
    for(int i = 1; i + k - 1 <= n; i++) {
        for(int j = i + 1; j + k - 1 <= n; j++) {
            int ri = min(n, i + k - 1), rj = min(n, j + k - 1);
            array<int, 2> midi, midj;
            midi[0] = (i + ri) / 2, midi[1] = (i + ri) % 2;
            midj[0] = (j + rj) / 2, midj[1] = (j + rj) % 2;
            if(midi == midj) {
                ans = max(ans, sum[i][n]);
            }
            else {
                auto check = [&](int mid) {
                    array<int, 2> x, y;
                    x[0] = midi[0] - a[mid][2], x[1] = midi[1] - a[mid][3];
                    y[0] = midj[0] - a[mid][2], y[1] = midj[1] - a[mid][3];
                    auto x1 = midi;
                    auto x2 = x1;
                    x2[0] = a[mid][2], x2[1] = a[mid][3];
                    if(x1 > x2) swap(x1, x2);
                    if(x1[1] > x2[1]) x[0] = x2[0] - x1[0] - 1, x[1] = 1;
                    else x[0] = x2[0] - x1[0], x[1] = x2[1] - x1[1];
                    auto y1 = midj;
                    auto y2 = y1;
                    y2[0] = a[mid][2], y2[1] = a[mid][3];
                    if(y1 > y2) swap(y1, y2);
                    if(y1[1] > y2[1]) y[0] = y2[0] - y1[0] - 1, y[1] = 1;
                    else y[0] = y2[0] - y1[0], y[1] = y2[1] - y1[1];

                    if(x <= y) return 1;
                    else return 0;
                };

                int lo = 0, hi = m;
                while(lo < hi) {
                    int mid = lo + hi + 1 >> 1;
                    if(check(mid)) lo = mid;
                    else hi = mid - 1;
                }
                //cout << i << ' ' << j << ' ' << lo << '\n';
                ans = max(ans, sum[i][lo] + sum[j][m] - sum[j][lo]);
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

    while(t--) {
        solve();
    }

    return 0;
}