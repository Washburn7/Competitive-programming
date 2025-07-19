#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa > xb) cout << "Draw\n";
    else {
        if((xb - xa) & 1) {
            int round = (xb - xa) / 2;
            int remain = (xb - xa) % 2;
            int L1 = (ya - round), R1 = (ya + round);
            int L2 = (yb - round), R2 = (yb + round);
            if(remain) L1--, R1++;
            L1 = max(1, L1), R1 = min(w, R1);
            L2 = max(1, L2), R2 = min(w, R2);
            if((L2 >= L1 && L2 <= R1) && (R2 >= L1 && R2 <= R1)) {
                cout << "Alice\n";
            }
            else {
                cout << "Draw\n";
            }
        }
        else {
            int round = (xb - xa) / 2;
            int L1 = (ya - round), R1 = (ya + round);
            int L2 = (yb - round), R2 = (yb + round);
            L1 = max(1, L1), R1 = min(w, R1);
            L2 = max(1, L2), R2 = min(w, R2);
            if((L1 >= L2 && L1 <= R2) && (R1 >= L2 && R1 <= R2)) {
                cout << "Bob\n";
            }
            else {
                cout << "Draw\n";
            }
        }
    }
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