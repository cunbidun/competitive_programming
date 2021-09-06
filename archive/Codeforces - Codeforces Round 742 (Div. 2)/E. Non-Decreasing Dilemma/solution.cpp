#include <bits/stdc++.h>

using namespace std;

#define left (i * 2 + 1)
#define right (i * 2 + 2)

struct segment_tree {
  int n;
  struct node {
    int l_val, r_val;
    long long n_pair;
    int l_len, r_len;
    int e;
  };
  vector<node> st;
  segment_tree(int _n) : n(_n) {
    st.assign(8 * n, {0, 0, 0, 0, 0, 0});
  }
  node combine(node n1, node n2) {
    node res = {0, 0, 0, 0, 0, 0};
    if (n1.e == 0) {
      return n2;
    }
    if (n2.e == 0) {
      return n1;
    }
    res.l_val = n1.l_val;
    res.r_val = n2.r_val;
    res.n_pair = n1.n_pair + n2.n_pair;
    res.l_len = n1.l_len;
    res.r_len = n2.r_len;
    if (n1.r_val <= n2.l_val) {
      res.n_pair += 1LL * n1.r_len * n2.l_len;
      if (n1.l_len == n1.e) {
        res.l_len += n2.l_len;
      }
      if (n2.l_len == n2.e) {
        res.r_len += n1.r_len;
      }
    }
    res.e = n1.e + n2.e;
    return res;
  }
  void update(int i, int l, int r, int p, int v) {
    if (r < p || p < l) {
      return;
    }
    if (p == l && r == p) {
      st[i] = {v, v, 1, 1, 1, 1};
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, p, v);
    update(i * 2 + 2, m + 1, r, p, v);
    st[i] = combine(st[left], st[right]);
  }
  node get_cnt(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return {0, 0, 0, 0, 0, 0};
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    auto n1 = get_cnt(i * 2 + 1, l, m, ql, qr);
    auto n2 = get_cnt(i * 2 + 2, m + 1, r, ql, qr);
    return combine(n1, n2);
  }
  void update(int p, int v) {
    update(0, 0, n - 1, p, v);
  }
  long long get_cnt(int L, int R) {
    return get_cnt(0, 0, n - 1, L, R).n_pair;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  segment_tree st(N + 1);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    st.update(i, x);
  }
  while (Q--) {
    int c, l, r;
    cin >> c >> l >> r;
    if (c == 1) {
      st.update(l, r);
    } else {
      cout << st.get_cnt(l, r) << '\n';
    }
  }
}
