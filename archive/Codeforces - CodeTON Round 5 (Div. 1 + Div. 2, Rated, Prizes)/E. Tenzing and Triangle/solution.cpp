/**
 *  author: cunbidun
 *  created: Saturday, 2023-08-26 16:11:51 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

// 0-indexed
template <typename T> struct segment_tree {
  int n;
  vector<T> st, lazy;

  segment_tree(int _n) : n(_n) {
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

  T _get(int i, int l, int r, int ql, int qr) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return numeric_limits<T>::min();
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(_get(i * 2 + 1, l, m, ql, qr), _get(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int l, int r, T v) { update(0, 0, n - 1, l, r, v); }
  T get(int l, int r) { return _get(0, 0, n - 1, l, r); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K, A;
  cin >> N >> K >> A;
  vector<array<int, 3>> p(N);
  int s = 0;
  for (int i = 0; i < N; i++) {
    cin >> p[i][0] >> p[i][1] >> p[i][2];
    s += p[i][2];
  }
  sort(p.begin(), p.end(), [](auto f, auto s) { return f[1] > s[1]; });
  segment_tree<int> st(K + 1);

  vector<int> f(K + 2, 0);
  int current = 0;
  for (int i = K - 1; i >= 0; i--) {
    st.update(i, i, f[i + 1]);
    st.update(i + 1, K, -A);
    while (current < N) {
      if (p[current][1] == i) {
        st.update(K - p[current][0], K, p[current][2]);
        current++;
      } else {
        break;
      }
    }
    f[i] = st.get(i, K);
  }
  cout << s - f[0] << '\n';
}
