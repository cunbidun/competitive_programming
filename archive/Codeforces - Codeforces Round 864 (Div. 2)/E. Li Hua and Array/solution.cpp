/**
 *  author: cunbidun
 *  created: Tuesday, 2023-09-05 21:27:55 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> phi(5e6 + 5), c1(5e6 + 5);

int get_common_phi(int x, int y) {
  if (x == y) {
    return x;
  }
  if (x > y) {
    swap(x, y);
  }
  return get_common_phi(x, phi[y]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  [&](int n) {
    for (int i = 0; i <= n; i++)
      phi[i] = i;

    for (int i = 2; i <= n; i++) {
      if (phi[i] == i) {
        for (int j = i; j <= n; j += i)
          phi[j] -= phi[j] / i;
      }
    }
  }(5e6);

  for (int i = 2; i <= 5e6; i++) {
    c1[i] = c1[phi[i]] + 1;
  }

  int N, Q;
  cin >> N >> Q;
  vector<int> a(N), c(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    c[i] = c1[a[i]];
  }

  struct segment_tree {
    int n;
    struct node {
      int sum, phi;
    };
    vector<node> st;
    vector<int> visited;
    segment_tree(int _n) : n(_n) {
      st.assign(4 * n, {0, -1});
      visited.assign(n * 4, 0);
    }
    node combine(node x, node y) {
      assert(x.phi != -1 || y.phi != -1);
      if (x.phi == -1) {
        swap(x, y);
      }
      return {x.sum + y.sum, (y.phi == -1) ? x.phi : get_common_phi(x.phi, y.phi)};
    }
    void build_tree(int i, int l, int r, vector<int> &a, vector<int> &c) {
      if (l == r) {
        st[i] = {c[l], a[l]};
        return;
      }
      int m = (l + r) / 2;
      build_tree(i * 2 + 1, l, m, a, c);
      build_tree(i * 2 + 2, m + 1, r, a, c);
      st[i] = combine(st[i * 2 + 1], st[i * 2 + 2]);
    };
    void update(int i, int l, int r, int L, int R) {
      if (r < L || R < l || visited[i] == 25) {
        return;
      }
      if (L <= l && r <= R) {
        visited[i]++;
      }
      if (l == r) {
        if (st[i].phi != 1) {
          st[i].phi = phi[st[i].phi];
          st[i].sum--;
        } else {
          assert(st[i].sum == 0);
        }
        return;
      }
      int m = (l + r) / 2;
      update(i * 2 + 1, l, m, L, R);
      update(i * 2 + 2, m + 1, r, L, R);
      st[i] = combine(st[i * 2 + 1], st[i * 2 + 2]);
    }

    node get(int i, int l, int r, int ql, int qr) {
      if (r < ql || qr < l) {
        return {0, -1};
      }
      if (ql <= l && r <= qr) {
        return st[i];
      }
      int m = (l + r) / 2;
      return combine(get(i * 2 + 1, l, m, ql, qr), get(i * 2 + 2, m + 1, r, ql, qr));
    }
    void update(int L, int R) { update(0, 0, n - 1, L, R); }
    node get(int L, int R) { return get(0, 0, n - 1, L, R); }
  };
  segment_tree st(N);
  st.build_tree(0, 0, N - 1, a, c);
  while (Q--) {
    int t, l, r;
    cin >> t >> l >> r;
    l--, r--;
    if (t == 1) {
      st.update(l, r);
    } else {
      auto node = st.get(l, r);
      cout << node.sum - (r - l + 1) * c1[node.phi] << '\n';
    }
  }
}
