/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-19 17:50:10 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  struct plane {
    int x;
    char c;
  };
  vector<vector<plane>> V(2 * MAX + 1), H(2 * MAX + 1), PD(2 * MAX + 1), ND(2 * MAX + 1);
  for (int i = 0; i < N; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    V[x].push_back({y, c});
    H[y].push_back({x, c});
    PD[x - y + 200000].push_back({x, c});
    ND[x + y].push_back({x, c});
  }
  auto process = [](vector<plane> &v, char d1, char d2, int c) -> int {
    int mn = 1e9;
    vector<plane> d1_list, d2_list;
    for (auto e : v) {
      if (e.c == d1) {
        d1_list.push_back(e);
      }
      if (e.c == d2) {
        d2_list.push_back(e);
      }
    }
    int pd1 = 0, pd2 = 0;
    while (pd1 < (int)d1_list.size() && pd2 < (int)d2_list.size()) {
      if (d1_list[pd1].x < d2_list[pd2].x) {
        mn = min(mn, (d2_list[pd2].x - d1_list[pd1].x) * c);
        pd1++;
      } else {
        pd2++;
      }
    }
    return mn;
  };
  int ans = 1e9;
  for (int i = 0; i <= 2 * MAX; i++) {
    sort(V[i].begin(), V[i].end(), [](auto f, auto s) { return f.x < s.x; });
    ans = min(ans, process(V[i], 'U', 'D', 5));

    sort(H[i].begin(), H[i].end(), [](auto f, auto s) { return f.x < s.x; });
    ans = min(ans, process(H[i], 'R', 'L', 5));

    sort(PD[i].begin(), PD[i].end(), [](auto f, auto s) { return f.x < s.x; });
    ans = min(ans, process(PD[i], 'R', 'D', 10));
    ans = min(ans, process(PD[i], 'U', 'L', 10));

    sort(ND[i].begin(), ND[i].end(), [](auto f, auto s) { return f.x < s.x; });
    ans = min(ans, process(ND[i], 'D', 'L', 10));
    ans = min(ans, process(ND[i], 'R', 'U', 10));
  }
  if (ans == 1e9) {
    cout << "SAFE" << '\n';
  } else {
    cout << ans << '\n';
  }
}
