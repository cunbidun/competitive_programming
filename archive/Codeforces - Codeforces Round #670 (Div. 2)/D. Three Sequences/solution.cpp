#include <bits/stdc++.h>

using namespace std;

// 1-based index: range update point query
template <typename T>
struct fenwick_tree_range {
  vector<T> bit;
  int n;
  fenwick_tree_range() {}
  fenwick_tree_range(int _n) { init(_n); }
  void init(int _n) {
    n = _n, bit.assign(n + 1, T{});
  }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v, p += p & -p;
    }
  }
  void update(int l, int r, T v) {
    update(l, v);
    update(r + 1, -v);
  }
  T get(int p) {
    T res{};
    while (p >= 1) {
      res += bit[p], p -= p & -p;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  auto cal = [&](long long f, long long u) {
    return (f - u) / 2;
  };
  fenwick_tree_range<long long> bit;
  bit.init(N);
  long long u = 0;
  for (int i = 1; i <= N; i++) {
    bit.update(i, i, a[i]);
  }
  for (int i = 2; i <= N; i++) {
    u += max(a[i] - a[i - 1], 0LL);
  }

  long long f = bit.get(1);
  cout << cal(f, u) + u << '\n';
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    long long x;
    cin >> l >> r >> x;
    if (l != 1) {
      long long val = bit.get(l) - bit.get(l - 1);
      if (val > 0) {
        u -= val;
      }
    }

    if (r != N) {
      long long val = bit.get(r + 1) - bit.get(r);
      if (val > 0) {
        u -= val;
      }
    }

    bit.update(l, r, x);

    if (l != 1) {
      long long val = bit.get(l) - bit.get(l - 1);
      if (val > 0) {
        u += val;
      }
    }
    if (r != N) {
      long long val = bit.get(r + 1) - bit.get(r);
      if (val > 0) {
        u += val;
      }
    }
    f = bit.get(1);
    cout << cal(f, u) + u << '\n';
  }
}
