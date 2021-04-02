#include <bits/stdc++.h>

using namespace std;

struct segtree {
  int n;
  vector<long long> st;
  segtree(int sz) {
    n = sz;
    st.assign(sz * 4, -1e18);
  }

  void update(int i, int l, int r, int p, long long v) {
    if (l > p || p > r) {
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
  };

  long long get_max(int i, int l, int r, int L, int R) {
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
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> h(n + 1), l(n + 1);
  vector<long long> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  stack<pair<int, int>> s;
  s.push({0, 0});
  for (int i = 1; i <= n; i++) {
    while (s.top().first > h[i]) {
      s.pop();
    }
    l[i] = s.top().second;
    s.push({h[i], i});
  }
  segtree tree(n + 1);
  vector<long long> f(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    long long mx = b[i] + f[i - 1];
    if (l[i] != i - 1) {
      mx = max(mx, b[i] + tree.get_max(0, 0, n, l[i] + 1, i - 1));
      // cout << i << ' ' << l[i] << ' ' << mx << '\n';
    }
    if (l[i] == 0) {
      mx = max(mx, b[i]);
    } else {
      mx = max(mx, f[l[i]]);
    }
    f[i] = mx;
    tree.update(0, 0, n, i, mx);
  }
  // for (int i : f) {
  //   cout << i << ' ';
  // }
  // cout << '\n';
  cout << f[n] << '\n';
}
