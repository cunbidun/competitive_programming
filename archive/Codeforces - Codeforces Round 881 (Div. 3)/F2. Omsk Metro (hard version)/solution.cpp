/**
 *  author: cunbidun
 *  created: Tuesday, 2023-08-22 23:38:32 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  struct e {
    int p, sum, mx, mn, mx_start, mn_start, mx_end, mn_end;
  };

  while (T--) {
    int N;
    cin >> N;
    int MX = N + 2;
    vector<vector<e>> st(MX, vector<e>(20));
    vector<int> lvl(MX);

    lvl[1] = 1;
    st[1][0] = {1, 1, 1, 1, 1, 1, 1, 1};

    auto combine = [&](e x, e y) -> e {
      e r = {0, 0, 0, 0, 0, 0, 0, 0};
      r.p = y.p;
      r.sum = x.sum + y.sum;
      r.mx_start = max(x.mx_start, x.sum + y.mx_start);
      r.mn_start = min(x.mn_start, x.sum + y.mn_start);
      r.mx_end = max(x.mx_end + y.sum, y.mx_end);
      r.mn_end = min(x.mn_end + y.sum, y.mn_end);
      r.mx = max({x.mx, y.mx, x.mx_end + y.mx_start});
      r.mn = min({x.mn, y.mn, x.mn_end + y.mn_start});
      return r;
    };

    auto jump = [&](int x, int l) -> e {
      e r = {x, 0, 0, 0, 0, 0, 0, 0};
      for (int i = 19; i >= 0; i--) {
        if ((l >> i) & 1) {
          r = combine(r, st[x][i]);
          x = r.p;
        }
      }
      return r;
    };
    auto lca = [&](int x, int y) {
      if (lvl[x] > lvl[y]) {
        swap(x, y);
      }
      auto r = jump(y, lvl[y] - lvl[x]);
      y = r.p;
      if (x == y) {
        return x;
      }
      for (int i = 19; i >= 0; i--) {
        if (st[y][i].p != st[x][i].p) {
          x = st[x][i].p;
          y = st[y][i].p;
        }
      }
      return st[x][0].p;
    };

    int new_v = 2;
    for (int event = 1; event <= N; event++) {
      char c;
      cin >> c;
      if (c == '+') {
        int v, x;
        cin >> v >> x;
        lvl[new_v] = lvl[v] + 1;
        st[new_v][0] = {v, x, x, x, x, x, x, x};
        for (int i = 1; i < 20; i++) {
          int p = st[new_v][i - 1].p;
          st[new_v][i] = combine(st[new_v][i - 1], st[p][i - 1]);
        }
        new_v++;
      } else {
        int u, v, k;
        cin >> u >> v >> k;
        auto l = lca(u, v);
        auto u_side = jump(u, lvl[u] - lvl[l] + 1);
        auto v_side = jump(v, lvl[v] - lvl[l] + 1);
        auto mx = max({u_side.mx, v_side.mx});
        auto mn = min({u_side.mn, v_side.mn});
        if (l != u && l != v) {
          v_side = jump(v, lvl[v] - lvl[l]);
          mx = max(mx, u_side.mx_end + v_side.mx_end);
          mn = min(mn, u_side.mn_end + v_side.mn_end);
        }
        if (mn <= k && k <= mx) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
}
