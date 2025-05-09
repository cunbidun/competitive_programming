#include <bits/stdc++.h>
#include <vector>
using namespace std;

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
  int N = 5e6 + 5;
  int Q;
  cin >> Q;
  fenwick_tree<int> t(N);
  vector<int> used(N);
  while (Q--) {
    int A, B;
    cin >> A >> B;
    if (A < N && !used[A]) {
      for (int i = A; i < N; i += A) {
        if (!used[i]) {
          used[i] = 1;
          t.update(i, 1);
        }
      }
    }
    int l = 1, r = N;
    while (l < r) {
      int m = (l + r) / 2;
      if (m - t.get(m) >= B) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << '\n';
  }
}
