#include <bits/stdc++.h>

using namespace std;

// 1-based index: point update range query
template <typename T>
struct fenwick_tree {
  vector<T> bit;
  int n;
  fenwick_tree() {}
  fenwick_tree(int _n) { init(_n); }
  void init(int _n) {
    n = _n, bit.assign(n + 1, T{});
  }
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
  const int MN = 3e5 + 5;
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  fenwick_tree<long long> bit(MN), cnt(MN);
  fenwick_tree_range<long long> bit2(MN);
  long long ans = 0;
  for (int k = 0; k < N; k++) {
    // a[i] % a[k]
    long long resf = bit.get(1, a[k]);
    for (int i = a[k]; i <= MN; i += a[k]) {
      int up = min(i + a[k] - 1, MN);
      resf += bit.get(i, up) - cnt.get(i, up) * i;
    }
    // a[k] % a[i];
    long long resb = 1LL * a[k] * cnt.get(a[k], MN);
    ans += resf + resb + a[k] * cnt.get(1, a[k]) - bit2.get(a[k]);
    for (int i = a[k]; i <= MN; i += a[k]) {
      int up = min(i + a[k] - 1, MN);
      bit2.update(i, up, i);
    }
    cout << ans << ' ';
    cnt.update(a[k], 1);
    bit.update(a[k], a[k]);
  }
  cout << '\n';
}
