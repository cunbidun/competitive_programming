#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
  int n;
  vector<T> st, lazy;
  segment_tree(int _n) : n(_n) {
    st.assign(4 * n, 0);
  }
  void update(int i, int l, int r, int p, int v) {
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
    st[i] = st[i * 2 + 1] + st[i * 2 + 2];
  }
  T get_sum(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return 0;
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return get_sum(i * 2 + 1, l, m, ql, qr) + get_sum(i * 2 + 2, m + 1, r, ql, qr);
  }
  void update(int p, int v) {
    update(0, 0, n - 1, p, v);
  }
  int get_sum(int L, int R) {
    return get_sum(0, 0, n - 1, L, R);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, T;
  cin >> N >> T;
  vector<array<int, 2>> v;
  segment_tree<int> segtree(N + 1);

  auto ask = [&](int l, int r) -> int {
    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
  };
  int f = 0;
  while (T--) {
    int K;
    cin >> K;
    if (K == -1) {
      return 0;
    }
    if (!f) {
      for (int i = 8; i <= N; i += 8) {
        v.push_back({i - ask(1, i), i});
      }
      if (N % 8 != 0) {
        v.push_back({N - ask(1, N), N});
      }
      f = 1;
    }
    int l = 0, r = (int)v.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      int res = v[m][0] - segtree.get_sum(1, v[m][1]);
      if (res < K) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    l = max(v[l][1] - 8 + 1, 1);
    r = min(l + 8 - 1, N);
    while (l < r) {
      int m = (l + r) / 2;
      int res = m - ask(1, m);
      if (res < K) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    cout << "! " << l << endl;
    segtree.update(l, 1);
  }
}
