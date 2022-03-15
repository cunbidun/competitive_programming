#include <bits/stdc++.h>

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
  int N, M;
  cin >> N >> M;
  fenwick_tree<int> bit(N);
  vector<array<int, 3>> a;
  for (int i = 0; i < M; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    a.push_back({l, r, x});
  }
  sort(a.begin(), a.end(), [](auto f, auto s) { return f[1] < s[1]; });
  set<int> pre;
  for (int i = 0; i <= N + 1; i++) {
    pre.insert(i);
  }
  vector<int> ans(N + 2);
  for (int i = 0; i < M; i++) {
    int cur = a[i][2] - bit.get(a[i][0], a[i][1]);
    int pos = a[i][1];
    while (cur > 0) {
      auto it = pre.upper_bound(pos);
      it--;
      pos = *it;
      ans[pos] = 1;
      bit.update(pos, 1);
      pre.erase(pos);
      cur--;
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << ' ';
  }
}
