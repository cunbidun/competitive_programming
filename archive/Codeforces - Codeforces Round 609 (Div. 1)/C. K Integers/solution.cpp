#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<int> p(N + 1);
  vector<long long> res(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  fenwick_tree<int> bit(N);
  for (int i = 1; i <= N; i++) {
    res[i] = res[i - 1] + bit.get(p[i], N);
    bit.update(p[i], 1);
  }
  fenwick_tree<long long> move(N);
  ordered_set s;
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    s.insert(p[i]);
    move.update(p[i], p[i]);
    int mid = *s.find_by_order(i / 2);
    long long left_sum = move.get(1, mid - 1);
    long long right_sum = move.get(mid + 1, N);
    long long target_left = 1LL * (i / 2) * (mid - 1 + mid - (i / 2)) / 2;
    long long target_right = 1LL * (i - i / 2 - 1) * (mid + 1 + mid + (i - i / 2 - 1)) / 2;
    ans = res[i] + target_left - left_sum + right_sum - target_right;
    cout << ans << ' ';
  }
  cout << '\n';
}
