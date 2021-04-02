#include <bits/stdc++.h>

using namespace std;

struct segment_tree_range_add_range_max {
  int sz;
  vector<int> lazy, seg;

  segment_tree_range_add_range_max(vector<pair<int, int>> &b) {
    sz = b.size();
    lazy.assign(4 * sz, 0);
    seg.assign(4 * sz, 0);
    build_tree(0, 0, sz - 1, b);
  }

  void build_tree(int i, int l, int r, vector<pair<int, int>> &b) {
    if (l > r) {
      return;
    }
    if (l == r) {
      seg[i] = -b[l].second;
      return;
    }
    int m = (l + r) / 2;
    build_tree(i * 2 + 1, l, m, b);
    build_tree(i * 2 + 2, m + 1, r, b);
    seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
  }
  void lazy_prop(int i, int l, int r) {
    if (lazy[i] != 0) {
      seg[i] += lazy[i];
      if (l != r) {
        lazy[i * 2 + 1] += lazy[i];
        lazy[i * 2 + 2] += lazy[i];
      }
    }
    lazy[i] = 0;
  }

  void update(int i, int l, int r, int L, int R, int val) {
    lazy_prop(i, l, r);
    if (R < l || r < L) {
      return;
    }
    if (L <= l && r <= R) {
      lazy[i] += val;
      lazy_prop(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, L, R, val);
    update(i * 2 + 2, m + 1, r, L, R, val);
    seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
  }

  void add(int l, int val) {
    update(0, 0, sz - 1, l, sz - 1, val);
  }

  int get_max(int i, int l, int r, int L, int R) {
    lazy_prop(i, l, r);
    if (R < l || r < L) {
      return -1e9 - 100;
    }
    if (L <= l || r <= R) {
      return seg[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, L, R), get_max(i * 2 + 2, m + 1, r, L, R));
  }
  int get_max() {
    return get_max(0, 0, sz - 1, 0, sz - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, p;
  cin >> n >> m >> p;
  vector<pair<int, int>> a(n), b(m);
  struct monster {
    int atk, def, coin;
  };
  vector<monster> c(p);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  for (int i = 0; i < p; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    c[i] = {x, y, z};
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end(), [](monster A, monster B) {
    return A.atk < B.atk;
  });
  segment_tree_range_add_range_max tree(b);
  int cur = 0;
  int ans = -2e9 - 99;
  for (int i = 0; i < n; i++) {
    int atk = a[i].first;
    int cost = a[i].second;
    while (cur < p && c[cur].atk < atk) {
      auto it = upper_bound(b.begin(), b.end(), make_pair(c[cur].def, (int)1e9));
      if (it != b.end()) {
        tree.add(it - b.begin(), c[cur].coin);
      }
      cur++;
    }
    ans = max(ans, tree.get_max() - cost);
  }
  cout << ans << '\n';
}
