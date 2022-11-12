#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// fenwick_tree
// 1-based index
template <typename T> struct fenwick_tree {
  vector<T> bit;
  int n;
  fenwick_tree() {}
  fenwick_tree(int _n) { init(_n); }
  void init(int _n) { n = _n, bit.assign(n + 1, T{}); }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v, p += p & -p;
    }
  }
  T get(int p) {
    T res{};
    while (p >= 1) {
      res += bit[p], p -= p & -p;
    }
    return res;
  }
  T get(int l, int r) { return (l > r) ? T{} : get(r) - get(l - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, M;
  cin >> H >> W >> M;
  vector<array<int, 2>> point(M);
  int mn_x = W, mn_y = H;

  set<array<int, 2>> s;
  for (int i = 0; i < M; i++) {
    cin >> point[i][0] >> point[i][1];
    s.insert(point[i]);
    if (point[i][0] == 1) {
      mn_x = min(mn_x, point[i][1]);
    }
    if (point[i][1] == 1) {
      mn_y = min(mn_y, point[i][0]);
    }
  }
  for (int i = mn_x + 1; i <= W; i++) {
    if (s.find({1, i}) == s.end()) {
      point.push_back({1, i});
    }
  }
  for (int i = mn_y + 1; i <= H; i++) {
    if (s.find({i, 1}) == s.end()) {
      point.push_back({i, 1});
    }
  }
  vector<int> mnH(H + 1, W + 1), mnW(W + 1, H + 1);
  for (auto [x, y] : point) {
    mnH[x] = min(mnH[x], y);
    mnW[y] = min(mnW[y], x);
  }
  vector<array<int, 2>> effective_point;
  for (auto [x, y] : point) {
    if (!(y > mnH[x] && x > mnW[y])) {
      effective_point.push_back({x, y});
    }
  }
  sort(effective_point.begin(), effective_point.end(), [](auto x, auto y) -> bool {
    if (x[1] == y[1]) {
      return x[0] < y[0];
    }
    return x[1] < y[1];
  });
  fenwick_tree<int> fw(H + 10);
  long long ans = 0;
  set<int> updated;
  set<int> checked;
  for (auto [x, y] : effective_point) {
    int actual = H + 1 - x;
    if (checked.find(y) == checked.end()) {
      ans += fw.get(actual - 1);
      checked.insert(y);
    }
    if (updated.find(actual) == updated.end()) {
      fw.update(actual, 1);
      updated.insert(actual);
    }
  }
  cout << 1LL * H * W - (ans + (int)effective_point.size()) << '\n';
}
