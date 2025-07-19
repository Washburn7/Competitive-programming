#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int h, w;
void solve() {
    cin >> h >> w;
    int n = 1 << h;
    vector<i64> a(n), b(n);
    vector<string> s(h);
    for(int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < w; i++) {
        int sta = 0;
        for(int j = 0; j < h; j++) {
            if(s[j][i] == '1') sta += 1 << j;
        }
        a[sta]++;
    }
    for(int i = 0; i < n; i++) {
        int c = 0;
        for(int j = 0; j < h; j++) {
            c += (i >> j & 1);
        }
        c = min(c, h - c);
        b[i] = c;
    }
    auto fwtxor = [&](vector<i64> &a, int op) {
        for(int i = 1; i < n; i *= 2) {
            for(int p = i << 1, j = 0; j < n; j += p) {
                for(int k = 0; k < i; k++) {
                    i64 x = a[j + k], y = a[i + j + k]; 
                    a[j + k] = (x + y);
                    a[i + j + k] = (x - y);
                    if(op == -1) {
                        a[j + k] = a[j + k] / 2;
                        a[i + j + k] = a[i + j + k] / 2;
                    }
                }
            }
        }
    };
    auto fwt_xor = [&](vector<i64> &a, vector<i64> &b) {
        auto A = a, B = b;
        fwtxor(A, 1), fwtxor(B, 1);
        for(int i = 0; i < n; i++) A[i] = A[i] * B[i];
        fwtxor(A, -1);
        return A;
    };
    auto A = fwt_xor(a, b);
    i64 ans = LLONG_MAX;
    for(int i = 0; i < n; i++) ans = min(ans, A[i]);
    cout << ans;
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