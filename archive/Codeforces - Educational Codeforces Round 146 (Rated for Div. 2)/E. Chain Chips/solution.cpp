/**
 *  author: cunbidun
 *  created: Friday, 2023-05-12 21:36:41 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

const long long INF = 1e16;
using namespace std;

struct segment_tree {
  int n;
  vector<array<long long, 4>> st;
  segment_tree(int _n) : n(_n) { st.assign(4 * n, {INF, INF, INF, INF}); }
  void update(int i, int l, int r, int p, long long v) {
    if (r < p || p < l) {
      return;
    }
    if (p == l && r == p) {
      st[i][1] = INF;
      st[i][0] = INF;
      st[i][2] = INF;
      st[i][3] = v;
      return;
    }
    int m = (l + r) / 2;

    int left = i * 2 + 1;
    int right = i * 2 + 2;

    update(left, l, m, p, v);
    update(right, m + 1, r, p, v);
    if (r - l + 1 == 2) {
      st[i][0] = INF;
      st[i][1] = st[left][3];
      st[i][2] = st[right][3];
      st[i][3] = st[left][3] + st[right][3];
    } else if (r - l + 1 == 3) {
      st[i][0] = st[left][2];
      st[i][1] = st[left][3];
      st[i][2] = st[left][2] + st[right][3];
      st[i][3] = min({st[left][1] + st[right][3], st[left][3] + st[right][3]});
    } else {
      st[i][0] = min({
          st[left][0] + st[right][1],
          st[left][2] + st[right][0],
          st[left][2] + st[right][1],
      });
      st[i][1] = min({
          st[left][3] + st[right][0],
          st[left][1] + st[right][1],
          st[left][3] + st[right][1],
      });
      st[i][2] = min({
          st[left][2] + st[right][2],
          st[left][2] + st[right][3],
          st[left][0] + st[right][3],
      });
      st[i][3] = min({st[left][1] + st[right][3], st[left][3] + st[right][2], st[left][3] + st[right][3]});
    }
  }

  void update(int p, long long v) { update(0, 0, n - 1, p, v); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N - 1);
  segment_tree st(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> a[i];
    st.update(i, a[i]);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int p, v;
    cin >> p >> v;
    p--;
    st.update(p, v);
    cout << st.st[0][3] * 2 << '\n';
  }
}
