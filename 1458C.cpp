#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int n, m;
void solve() {
    cin >> n >> m;
    vector a(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    string s;
    cin >> s;
    vector<int> pos(4), sum(4);
    for(int i = 1; i <= 3; i++) pos[i] = i;
    for(int i = 0; i < m; i++) {
        if(s[i] == 'R') {
            for(int j = 1; j <= 3; j++) {
                if(pos[j] == 2) sum[j]++;
            }
        }
        else if(s[i] == 'L') {
            for(int j = 1; j <= 3; j++) {
                if(pos[j] == 2) sum[j]--;
            }
        }
        else if(s[i] == 'D') {
            for(int j = 1; j <= 3; j++) {
                if(pos[j] == 1) sum[j]++;
            }
        }
        else if(s[i] == 'U') {
            for(int j = 1; j <= 3; j++) {
                if(pos[j] == 1) sum[j]--;
            }
        }
        else if(s[i] == 'I') {
            int x, y;
            for(int j = 1; j <= 3; j++) {
                if(pos[j] == 2) x = j;
                if(pos[j] == 3) y = j;
            }
            swap(pos[x], pos[y]);
        }
        else if(s[i] == 'C') {
            int x, y;
            for(int j = 1; j <= 3; j++) {
                if(pos[j] == 1) x = j;
                if(pos[j] == 3) y = j;
            }
            swap(pos[x], pos[y]);
        }
    }
    vector ans(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x = i, y = j, z = a[i][j];
            vector<int> v = {0, x, y, z};
            vector<int> v2(4, 0);
            for(int k = 1; k <= 3; k++) {
                v2[pos[k]] = v[k] + sum[k];
            }
            v2[1] = ((v2[1] % n) + n) % n;
            if(v2[1] == 0) v2[1] = n;
            v2[2] = ((v2[2] % n) + n) % n;
            if(v2[2] == 0) v2[2] = n;
            v2[3] = ((v2[3] % n) + n) % n;
            if(v2[3] == 0) v2[3] = n;
            ans[v2[1]][v2[2]] = v2[3];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
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