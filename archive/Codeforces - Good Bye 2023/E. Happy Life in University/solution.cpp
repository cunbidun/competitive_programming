#include <bits/stdc++.h>

using namespace std;

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

// 0-indexed
template <typename T> struct segtree_rsum_rmin {
  int n;
  vector<T> st, lazy;
  segtree_rsum_rmin(int _n) : n(_n) {
    st.assign(4 * n, T{});
    lazy.assign(4 * n, T{});
  }
  void lazy_prop(int i, int l, int r) {
    if (lazy[i] != 0) {
      st[i] += lazy[i];
      if (l != r) {
        lazy[i * 2 + 1] += lazy[i];
        lazy[i * 2 + 2] += lazy[i];
      }
    }
    lazy[i] = 0;
  }

  void update(int i, int l, int r, int ql, int qr, T v) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      lazy[i] += v;
      lazy_prop(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, ql, qr, v);
    update(i * 2 + 2, m + 1, r, ql, qr, v);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }

  T get_max(int i, int l, int r, int ql, int qr) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return numeric_limits<T>::min();
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, ql, qr), get_max(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int l, int r, T v) { update(0, 0, n - 1, l, r, v); }
  T get_max(int l, int r) { return get_max(0, 0, n - 1, l, r); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<int>> g(N + 1);
    vector<vector<int>> over(N + 1);
    vector<int> a(N + 1);
    vector<int> p(N + 1);
    vector<int> last(N + 1);
    vector<int> tin(N + 1), tout(N + 1);
    for (int i = 2; i <= N; i++) {
      cin >> p[i];
      g[p[i]].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    int cnt = 0;
    yc([&](auto dfs, int u) -> void {
      cnt++;
      tin[u] = cnt;
      int current = last[a[u]];
      if (current) {
        over[current].push_back(u);
      }
      last[a[u]] = u;
      for (int v : g[u]) {
        dfs(v);
      }
      last[a[u]] = current;
      tout[u] = cnt;
    })(1);

    long long ans = 1;
    segtree_rsum_rmin<int> st(N + 1);
    yc([&](auto dfs, int u) -> void {
      for (int v : g[u]) {
        dfs(v);
      }
      st.update(tin[u], tout[u], 1);
      for (int v : over[u]) {
        st.update(tin[v], tout[v], -1);
      }
      int mx = 1;
      for (int v : g[u]) {
        auto res = st.get_max(tin[v], tout[v]);
        ans = max(ans, 1LL * mx * res);
        mx = max(res, mx);
      }
    })(1);
    cout << ans << '\n';
  }
}
