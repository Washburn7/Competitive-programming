#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return ;
    }
    for(int i = (n - 3) / 2; i >= 0; i--) {
        int cur = 0;
        cout << 1;
        cur++;
        for(int j = 1; j <= i; j++) cout << 0, cur++;
        cout << 6;
        cur++;
        for(int j = 1; j <= i; j++) cout << 0, cur++;
        cout << 9;
        cur++;
        for(int j = cur + 1; j <= n; j++) cout << 0;
        cout << '\n';
        cur = 0;
        cout << 9;
        cur++;
        for(int j = 1; j <= i; j++) cout << 0, cur++;
        cout << 6;
        cur++;
        for(int j = 1; j <= i; j++) cout << 0, cur++;
        cout << 1;
        cur++;
        for(int j = cur + 1; j <= n; j++) cout << 0;
        cout << '\n';
    }
    cout << 196;
    for(int j = 4; j <= n; j++) cout << 0;
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