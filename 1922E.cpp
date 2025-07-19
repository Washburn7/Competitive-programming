#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"  // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) (void)417
#endif
using i64 = int64_t;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    i64 x;
    cin >> x;
    vector<i64> ans;
    int a = -100, b = 100;
    while (x > 1) {
      if (x % 2 == 1) {
        ans.push_back(a++);
        x -= 1;
      } else {
        ans.push_back(b--);
        x /= 2;
      }
    }
    ranges::reverse(ans);
    cout << ans.size() << "\n";
    for (int x : ans) { cout << x << " "; }
    cout << "\n";
  }
}