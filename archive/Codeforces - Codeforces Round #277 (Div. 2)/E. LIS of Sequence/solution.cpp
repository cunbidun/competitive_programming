#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
  int n;
  vector<int> st;
  segment_tree(int _n) : n(_n) {
    st.assign(4 * n, 0);
  }
  void update(int i, int l, int r, int p, int v) {
    if (p < l || r < p) {
      return;
    }
    if (l == r && l == p) {
      st[i] = v;
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, p, v);
    update(i * 2 + 2, m + 1, r, p, v);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }
  int get_max(int i, int l, int r, int L, int R) {
    if (r < L || R < l || R < L) {
      return -1;
    }
    if (L <= l && r <= R) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, L, R), get_max(i * 2 + 2, m + 1, r, L, R));
  }
  void update(int p, int v) {
    update(0, 0, n - 1, p, v);
  }
  int get_max(int L, int R) {
    return get_max(0, 0, n - 1, L, R);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  segment_tree left(1e5 + 1);
  for (int i = 0; i < n; i++) {
    l[i] = left.get_max(0, a[i] - 1);
    left.update(a[i], l[i] + 1);
  }
  segment_tree right(1e5 + 1);
  for (int i = n - 1; i >= 0; i--) {
    r[i] = right.get_max(a[i] + 1, 1e5 + 1);
    right.update(a[i], r[i] + 1);
  }

  vector<int> cnt(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, 1 + l[i] + r[i]);
  }
  for (int i = 0; i < n; i++) {
    if (1 + l[i] + r[i] == mx) {
      cnt[l[i]]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (l[i] + r[i] + 1 != mx) {
      cout << 1;
    } else {
      if (cnt[l[i]] == 1) {
        cout << 3;
      } else {
        cout << 2;
      }
    }
  }
  cout << "\n";
}
