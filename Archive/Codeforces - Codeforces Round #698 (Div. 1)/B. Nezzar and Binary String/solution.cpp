#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
  vector<int> st, lazy;
  int n;

  segment_tree(int _n) : n(_n) {
    st.assign(4 * _n, 0);
    lazy.assign(4 * _n, -1);
  }

  void build_tree(int i, int l, int r, vector<int> &a) {
    if (l == r) {
      st[i] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build_tree(i * 2 + 1, l, m, a);
    build_tree(i * 2 + 2, m + 1, r, a);
    st[i] = st[i * 2 + 1] + st[i * 2 + 2];
  }

  void lazy_prop(int i, int l, int r) {
    if (lazy[i] != -1) {
      st[i] = lazy[i] * (r - l + 1);
      if (l != r) {
        lazy[i * 2 + 1] = lazy[i];
        lazy[i * 2 + 2] = lazy[i];
      }
    }
    lazy[i] = -1;
  }

  void update(int i, int l, int r, int L, int R, int v) {
    lazy_prop(i, l, r);
    if (R < l || r < L) {
      return;
    }
    if (L <= l && r <= R) {
      lazy[i] = v;
      lazy_prop(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, L, R, v);
    update(i * 2 + 2, m + 1, r, L, R, v);
    st[i] = st[i * 2 + 1] + st[i * 2 + 2];
  }

  int get_sum(int i, int l, int r, int L, int R) {
    lazy_prop(i, l, r);
    if (R < l || r < L) {
      return 0;
    }
    if (L <= l && r <= R) {
      return st[i];
    }
    int m = (l + r) / 2;
    return get_sum(i * 2 + 1, l, m, L, R) + get_sum(i * 2 + 2, m + 1, r, L, R);
  }

  int get_sum(int l, int r) {
    return get_sum(0, 0, n - 1, l, r);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n), f(n);
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    a[i] = x - '0';
  }
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    f[i] = x - '0';
  }

  segment_tree tree(n);
  tree.build_tree(0, 0, n - 1, f);
  vector<pair<int, int>> Q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    Q.push_back({l, r});
  }
  reverse(Q.begin(), Q.end());
  for (auto [l, r] : Q) {
    int cnt = tree.get_sum(0, 0, n - 1, l, r);
    if (cnt * 2 == r - l + 1) {
      cout << "NO\n";
      return;
    }
    tree.update(0, 0, n - 1, l, r, (cnt > (r - l + 1) / 2));
  }
  for (int i = 0; i < n; i++) {
    if (tree.get_sum(i, i) != a[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
