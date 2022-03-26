#ifdef __APPLE__
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    string I, P;
    cin >> I >> P;
    int cur = 0;
    if (P.size() < I.size()) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    for (int i = 0; i < (int)P.size(); i++) {
      if (P[i] == I[cur]) {
        cur++;
      }
      if (cur == (int)I.size()) {
        break;
      }
    }
    if (cur != (int)I.size()) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << P.size() - I.size() << '\n';
  }
}
