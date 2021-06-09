#include <bits/stdc++.h>

using namespace std;

template <class T>
struct segtree {
  int n;
  vector<T> st, lazy;

  segtree(int sz) {
    n = sz;
    st.assign(sz * 6, 0);
    lazy.assign(sz * 6, 0);
  }

  void lazy_update(int i, int l, int r) {
    st[i] += lazy[i];
    if (l != r) {
      lazy[2 * i + 1] += lazy[i];
      lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
  }

  void update(int i, int l, int r, int ql, int qr, T v) {
    lazy_update(i, l, r);
    if (l > qr || ql > r || l > r) {
      return;
    }
    if (ql <= l && r <= qr) {
      lazy[i] += v;
      lazy_update(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, ql, qr, v);
    update(i * 2 + 2, m + 1, r, ql, qr, v);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }

  T get_max(int i, int l, int r, int L, int R) {
    lazy_update(i, 1, n);
    if (l > R || L > r) {
      return -1e18;
    }
    if (L <= l && r <= R) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, L, R),
               get_max(i * 2 + 2, m + 1, r, L, R));
  }
  void update(int l, int r, T v) {
    update(0, 0, n - 1, l, r, v);
  }
  T get_max(int l, int r) {
    return get_max(0, 0, n - 1, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  int64_t K;
  cin >> N >> K;
  struct e {
    int l, r;
    int64_t p;
    int i;
  };
  int MX = 2e5;
  segtree<int64_t> sg(MX + 10);
  for (int i = 1; i <= MX; i++) {
    sg.update(i, MX, -K);
  }
  vector<e> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i].l >> a[i].r >> a[i].p;
    a[i].i = i;
  }
  sort(a.begin(), a.end(), [](auto A, auto B) {
    return A.l < B.l;
  });

  int64_t ans = 0;
  int l = -1, r = -1;
  vector<int> v;
  int p = -1;
  for (int i = N - 1; i >= 0; i--) {
    sg.update(a[i].r, MX, a[i].p);
    int64_t val = sg.get_max(a[i].l, MX) + K * (a[i].l - 1);
    if (ans < val) {
      p = i;
      l = a[i].l;
      ans = val;
    }
  }
  cout << ans << ' ';
  if (l == -1) {
    cout << '\n';
    return 0;
  }
  for (int i = 0; i < p; i++) {
    sg.update(a[i].r, MX, -a[i].p);
  }
  for (int i = l; i <= MX; i++) {
    if (sg.get_max(l, i) + K * (l - 1) == ans) {
      r = i;
      break;
    }
  }
  cout << l << ' ' << r << ' ';
  for (auto e : a) {
    if (l <= e.l && e.r <= r) {
      v.push_back(e.i);
    }
  }
  cout << v.size() << '\n';
  for (int i : v) {
    cout << i + 1 << ' ';
  }
  cout << '\n';
}
