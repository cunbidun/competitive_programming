#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, S;
    cin >> R >> S;
    if (R == 1) {
      cout << 0 << '\n';
    } else {
      vector<pair<int, int>> v;
      vector<pair<int, int>> ans;
      for (int j = 0; j < S; j++) {
        for (int i = 0; i < R; i++) {
          v.push_back({i, 1});
        }
      }
      auto swap = [&ans](vector<pair<int, int>> x, int a, int b) {
        int A = 0, B = 0;
        vector<pair<int, int>> new_x;
        for (int i = a; i < a + b; i++) {
          B += x[i].second;
          new_x.push_back(x[i]);
        }
        for (int i = 0; i < a; i++) {
          A += x[i].second;
          new_x.push_back(x[i]);
        }
        for (int i = a + b; i < (int)x.size(); i++) {
          new_x.push_back(x[i]);
        }
        vector<pair<int, int>> r;
        r.push_back(new_x[0]);
        for (int i = 1; i < (int)new_x.size(); i++) {
          if (new_x[i - 1].first != new_x[i].first) {
            r.push_back(new_x[i]);
          } else {
            r[(int)r.size() - 1].second += new_x[i].second;
          }
        }
        ans.push_back({A, B});
        return r;
      };
      while (1) {
        if ((int)v.size() == R) {
          break;
        }
        if ((int)v.size() == R + 1) {
          v = swap(v, 1, R);
        } else {
          v = swap(v, 2, R - 1);
        }
      }
      cout << ans.size() << '\n';
      for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
      }
    }
  }
}
