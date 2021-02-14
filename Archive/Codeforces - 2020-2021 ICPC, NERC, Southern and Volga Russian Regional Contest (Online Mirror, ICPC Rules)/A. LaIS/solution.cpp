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
    if (r < L || R < l) {
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), q(n, -3);
    vector<vector<int>> l(n, vector<int>());
    segment_tree tree(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    stack<pair<int, int>> s;
    s.push({a[0], 0});
    for (int i = 1; i < n; i++) {
      while (!s.empty() && s.top().first < a[i]) {
        s.pop();
      }
      if (!s.empty()) {
        if (s.top().second > 0) {
          l[s.top().second - 1].push_back(i);
        } else {
          q[i] = 0;
        }
      }
      s.push({a[i], i});
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int mx = 0;
      mx = max(tree.get_max(1, a[i]) + 1, q[i] + 2);
      tree.update(a[i], mx);
      ans = max(ans, mx);
      for (int j : l[i]) {
        q[j] = tree.get_max(1, a[j]);
      }
    }
    cout << ans << "\n";
  }
}
