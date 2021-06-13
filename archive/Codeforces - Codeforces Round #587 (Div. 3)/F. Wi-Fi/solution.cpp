#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
  int n;
  vector<T> st, lazy;
  segment_tree(int _n) : n(_n) {
    st.assign(8 * n, 0);
  }
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
    st[i] = min(st[i * 2 + 1], st[i * 2 + 2]);
  }
  T get_min(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return 1e18;
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return min(get_min(i * 2 + 1, l, m, ql, qr), get_min(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int p, T v) {
    update(0, 0, n - 1, p, v);
  }
  T get_min(int L, int R) {
    return get_min(0, 0, n - 1, L, R);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> v;
  for (int i = 1; i <= N; i++) {
    char c;
    cin >> c;
    if (c == '1') {
      v.push_back(i);
    }
  }
  int cur = 0;
  segment_tree<long long> seg(N + 1);
  for (int i = 1; i <= N; i++) {
    while (cur < (int)v.size() && v[cur] + K < i) {
      cur++;
    }
    if (cur < (int)v.size() && v[cur] <= i && v[cur] + K >= i) {
      long long res = seg.get_min(max(0, v[cur] - K - 1), v[cur] - 1) + v[cur];
      seg.update(i, res);
    } else {
      seg.update(i, seg.get_min(i - 1, i - 1) + i);
    }
  }
  cout << seg.get_min(N, N) << '\n';
}
