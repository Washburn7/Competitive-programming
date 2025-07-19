#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
constexpr int P = 1e9 + 7;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
Z dp[110][110][110];
void solve() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    vector<Z> pw(101);
    vector<i64> len(101);
    len[0] = len[1] = 1;
    for(int i = 2; i <= 100; i++) len[i] = (len[i - 1] + len[i - 2]) % (P - 1);
    for(int i = 0; i <= 100; i++) pw[i] = power((Z)2, len[i]);
    s = ' ' + s;
    for(int i = 1; i <= n; i++) dp[s[i] - '0'][i][i] = 1;
    for(int i = 2; i <= x; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = j; k <= n; k++) {
                if(k == n) dp[i][j][k] += dp[i - 1][j][k] * pw[i - 2];
                else dp[i][j][k] += dp[i - 1][j][k];
                if(j == 1) dp[i][j][k] += dp[i - 2][j][k] * pw[i - 1];
                else dp[i][j][k] += dp[i - 2][j][k];
                for(int p = j; p < k; p++) {
                    dp[i][j][k] += dp[i - 1][j][p] * dp[i - 2][p + 1][k];
                }
            }
        }
    }
    cout << dp[x][1][n];
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