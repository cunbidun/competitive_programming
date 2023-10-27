#include <bits/stdc++.h>

using namespace std;

template <typename T> struct sgtree_p_update_r_max {
  int n;
  vector<T> st;
  sgtree_p_update_r_max(int _n) : n(_n) { st.assign(4 * n, 0); }
  void update(int i, int l, int r, int p, T v) {
    if (r < p || p < l) {
      return;
    }
    if (p == l && r == p) {
      st[i] = v;
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, p, v);
    update(i * 2 + 2, m + 1, r, p, v);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }
  T get_max(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return numeric_limits<T>::min();
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, ql, qr), get_max(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int p, T v) { update(0, 0, n - 1, p, v); }
  T get_max(int L, int R) {
    if (L > R) {
      return 0;
    }
    return get_max(0, 0, n - 1, L, R);
  }
};

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
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> a(N + 1);
  vector<int> sum(N + 1);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  for (int i = 1; i <= N; i++) {
    sum[i] = sum[i - 1] + a[i].size();
  }
  sgtree_p_update_r_max<int> st(N);
  vector<array<int, 3>> events;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < (int)a[i].size() - 1; j++) {
      int val = st.get_max(a[i][j] + 1, a[i][j + 1] - 1);
      if (val == 0) {
        events.push_back({1, i, 0});
        events.push_back({i + 1, i, 1});
      } else {
        events.push_back({min(i, val + 1), i, 0});
        events.push_back({i + 1, i, 1});
      }
    }
    for (int j : a[i]) {
      st.update(j, i);
    }
  }
  sort(events.begin(), events.end());
  vector<vector<array<int, 2>>> q(N + 1);

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    q[l].push_back({r, i});
  }

  fenwick_tree<int> bit(N + 1);
  int p = 0;
  vector<int> ans(Q);
  for (int L = 1; L <= N; L++) {
    while (p < (int)events.size() && events[p][0] == L) {
      if (events[p][2] == 0) {
        bit.update(events[p][1], 1);
      } else {
        bit.update(events[p][1], -1);
      }
      p++;
    }
    for (auto [R, i] : q[L]) {
      int total = sum[R] - sum[L - 1];
      int discount = bit.get(R);
      ans[i] = total - discount;
    }
  }
  for (int i : ans) {
    cout << i << '\n';
  }
}
