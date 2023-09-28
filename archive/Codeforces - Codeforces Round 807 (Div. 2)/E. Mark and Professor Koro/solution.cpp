/**
 *  author: cunbidun
 *  created: Friday, 2023-09-22 00:04:05 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

template <typename T> struct segment_tree {
  int n;
  struct node {
    int f0, l0, f1, l1;
  };
  vector<node> st;
  vector<int> lazy;
  segment_tree(int _n) : n(_n) {
    st.assign(4 * n, {});
    lazy.assign(4 * n, -1);
  }
  node combine(node &n1, node &n2) {
    return {min(n1.f0, n2.f0), max(n1.l0, n2.l0), min(n1.f1, n2.f1), max(n1.l1, n2.l1)};
  }
  void build(int i, int l, int r, vector<int> &a) {
    if (l == r) {
      if (a[l] == 0) {
        st[i] = {l, r, INF, -1};
      } else {
        st[i] = {INF, -1, l, r};
      }
      return;
    }
    int m = (l + r) / 2;
    build(i * 2 + 1, l, m, a);
    build(i * 2 + 2, m + 1, r, a);
    st[i] = combine(st[i * 2 + 1], st[i * 2 + 2]);
  }

  void lazy_update(int i, int l, int r) {
    if (lazy[i] != -1) {
      if (lazy[i] == 0) {
        st[i] = {l, r, INF, -1};
      } else {
        st[i] = {INF, -1, l, r};
      }
      if (l != r) {
        lazy[i * 2 + 1] = lazy[i];
        lazy[i * 2 + 2] = lazy[i];
      }
      lazy[i] = -1;
    }
  }

  void update(int i, int l, int r, int ql, int qr, int v) {
    lazy_update(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return;
    }
    if (ql <= l && r <= qr) {
      lazy[i] = v;
      lazy_update(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, ql, qr, v);
    update(i * 2 + 2, m + 1, r, ql, qr, v);
    st[i] = combine(st[i * 2 + 1], st[i * 2 + 2]);
  }

  node get(int i, int l, int r, int ql, int qr) {
    lazy_update(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return {INF, -1, INF, -1};
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    auto left = get(i * 2 + 1, l, m, ql, qr);
    auto right = get(i * 2 + 2, m + 1, r, ql, qr);
    return combine(left, right);
  }

  void update(int L, int R, int val) { update(0, 0, n - 1, L, R, val); }
  node get(int L, int R) { return get(0, 0, n - 1, L, R); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  int MX = 2e5 + 30;
  vector<int> cnt(MX + 2);
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= MX; i++) {
    cnt[i + 1] += cnt[i] / 2;
    cnt[i] %= 2;
  }
  segment_tree<int> st(MX + 1);
  st.build(0, 0, MX, cnt);

  while (Q--) {
    int p, x;
    cin >> p >> x;
    p--;
    int b = a[p], f = x;
    a[p] = x;

    auto e = st.get(b, MX);

    if (b <= e.f1 - 1) {
      st.update(b, e.f1 - 1, 1);
    }
    st.update(e.f1, e.f1, 0);

    e = st.get(f, MX);
    if (f <= e.f0 - 1) {
      st.update(f, e.f0 - 1, 0);
    }
    st.update(e.f0, e.f0, 1);
    cout << st.get(0, MX).l1 << '\n';
  }
}
