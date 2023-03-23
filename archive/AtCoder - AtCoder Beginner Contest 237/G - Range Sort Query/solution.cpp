/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-19 17:50:05 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct segment_tree {
  struct node {
    bool empty;
    int pos_one;
    int sorted;
    int num_zero;
  };
  int get_pos_one(node l, node r) {
    if (l.pos_one != -1) {
      return l.pos_one;
    }
    if (r.pos_one != -1) {
      return r.pos_one;
    }
    return -1;
  }
  int n;
  vector<node> st, lazy;

  segment_tree(int _n) : n(_n) {
    st.assign(4 * n, {});
    lazy.assign(4 * n, {true, -1, 0, 0});
  }

  void lazy_update(int i, int l, int r) {
    if (!lazy[i].empty) {
      st[i] = lazy[i];
      if (l != r) {
        int m = (l + r) / 2;
        lazy[i * 2 + 1].empty = false;
        lazy[i * 2 + 2].empty = false;

        lazy[i * 2 + 1].sorted = lazy[i].sorted;
        lazy[i * 2 + 2].sorted = lazy[i].sorted;

        if (l <= lazy[i].pos_one && lazy[i].pos_one <= m) {
          lazy[i * 2 + 1].pos_one = lazy[i].pos_one;
        } else {
          lazy[i * 2 + 1].pos_one = -1;
        }
        if (m + 1 <= lazy[i].pos_one && lazy[i].pos_one <= r) {
          lazy[i * 2 + 2].pos_one = lazy[i].pos_one;
        } else {
          lazy[i * 2 + 2].pos_one = -1;
        }

        if (lazy[i].sorted == -1) {
          lazy[i * 2 + 1].num_zero = min(lazy[i].num_zero, m - l + 1);
          lazy[i * 2 + 2].num_zero = lazy[i].num_zero - lazy[i * 2 + 1].num_zero;
        } else {
          lazy[i * 2 + 2].num_zero = min(lazy[i].num_zero, r - (m + 1) + 1);
          lazy[i * 2 + 1].num_zero = lazy[i].num_zero - lazy[i * 2 + 2].num_zero;
        }
      }
    }
    lazy[i] = {true, -1, 0, 0};
  }

  void build_tree(int i, int l, int r, vector<int> &a) {
    if (l == r) {
      st[i].empty = false;
      if (a[l] == 1) {
        st[i].pos_one = l;
      } else {
        st[i].pos_one = -1;
      }
      st[i].sorted = 0;
      st[i].num_zero = (a[l] == 0);
      return;
    }
    int m = (l + r) / 2;
    build_tree(i * 2 + 1, l, m, a);
    build_tree(i * 2 + 2, m + 1, r, a);
    st[i] = {false, get_pos_one(st[i * 2 + 1], st[i * 2 + 2]), 0, st[i * 2 + 1].num_zero + st[i * 2 + 2].num_zero};
  }

  void update(int i, int l, int r, int ql, int qr, node d) {
    lazy_update(i, l, r);
    if (r < ql || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      lazy[i].empty = false;
      if (l <= d.pos_one && d.pos_one <= r) {
        lazy[i].pos_one = d.pos_one;
      } else {
        lazy[i].pos_one = -1;
      }
      lazy[i].sorted = d.sorted;
      if (d.sorted == -1) {
        lazy[i].num_zero = min(max(ql + d.num_zero - l, 0), r - l + 1);
      } else {
        lazy[i].num_zero = min(max(r - (qr - d.num_zero), 0), r - l + 1);
      }
      lazy_update(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, ql, qr, d);
    update(i * 2 + 2, m + 1, r, ql, qr, d);
    st[i] = {
        false, get_pos_one(st[i * 2 + 1], st[i * 2 + 2]), d.sorted, st[i * 2 + 1].num_zero + st[i * 2 + 2].num_zero};
  }

  node get(int i, int l, int r, int ql, int qr) {
    lazy_update(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return {false, -1, 0, 0};
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    auto left = get(i * 2 + 1, l, m, ql, qr);
    auto right = get(i * 2 + 2, m + 1, r, ql, qr);
    return {false, get_pos_one(left, right), false, left.num_zero + right.num_zero};
  }

  void update(int l, int r, node d) { update(0, 0, n - 1, l, r, d); }
  node get_min(int l, int r) { return get(0, 0, n - 1, l, r); }
  void build_tree(vector<int> &a) { build_tree(0, 0, n - 1, a); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q, X;
  cin >> N >> Q >> X;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] < X) {
      a[i] = 0;
    } else if (a[i] == X) {
      a[i] = 1;
    } else {
      a[i] = 2;
    }
  }
  auto st = segment_tree(N);
  st.build_tree(a);

  while (Q--) {
    int c, l, r;
    cin >> c >> l >> r;
    l--, r--;
    auto node = st.get_min(l, r);
    if (c == 1) {
      node.sorted = -1;
      if (node.pos_one != -1) {
        node.pos_one = l + node.num_zero;
      }
    } else {
      node.sorted = 1;
      if (node.pos_one != -1) {
        node.pos_one = (r - node.num_zero);
      }
    }
    st.update(l, r, node);
  }

  cout << st.st[0].pos_one + 1 << '\n';
}
