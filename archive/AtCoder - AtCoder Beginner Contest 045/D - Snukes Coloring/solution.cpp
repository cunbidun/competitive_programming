#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, N;
  cin >> H >> W >> N;

  set<array<int, 2>> s;
  set<array<int, 2>> used;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({x, y});
  }
  vector<long long> ans(10);
  ans[0] = 1LL * (H - 3 + 1) * (W - 3 + 1);
  for (auto [x, y] : s) {
    for (int i = max(1, x - 3); i <= x; i++) {
      for (int j = max(1, y - 3); j <= y; j++) {
        if (i + 3 - 1 <= H && j + 3 - 1 <= W &&
            used.find({i, j}) == used.end()) {
          used.insert({i, j});
          int cnt = 0;
          for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
              cnt += s.find({k, l}) != s.end();
            }
          }
          if (cnt != 0) {
            ans[0]--;
            ans[cnt]++;
          }
        }
      }
    }
  }
  for (auto i : ans) {
    cout << i << '\n';
  }
}
