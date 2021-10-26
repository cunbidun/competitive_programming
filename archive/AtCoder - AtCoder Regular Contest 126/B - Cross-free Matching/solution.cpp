#include <bits/stdc++.h>

using namespace std;

template <typename T> struct segment_tree {
  int n;
  vector<T> st;

  segment_tree(int _n) : n(_n) { st.assign(8 * n, 0); }
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
      return 0;
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, ql, qr),
               get_max(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int p, T v) { update(0, 0, n - 1, p, v); }
  T get_max(int L, int R) {
    if (L > R) {
      return 0;
    }
    return get_max(0, 0, n - 1, L, R);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  segment_tree<int> st(N + 5);
  int ans = 0;
  vector<array<int, 2>> p;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back({a, b});
  }

  sort(p.begin(), p.end(), [](auto f, auto s) {
    if (f[0] != s[0]) {
      return f[0] < s[0];
    }
    return f[1] > s[1];
  });
  for (auto [a, b] : p) {
    int f = st.get_max(1, b - 1) + 1;
    ans = max(ans, f);
    st.update(b, f);
  }
  cout << ans << '\n';
}
