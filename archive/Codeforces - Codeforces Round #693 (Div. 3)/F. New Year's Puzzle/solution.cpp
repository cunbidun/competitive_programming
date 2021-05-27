#include <bits/stdc++.h>

using namespace std;

template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() {
    cout << endl;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    vector<pair<int, int>> pp;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      p.push_back({y, x - 1});
    }
    sort(p.begin(), p.end());
    int mx = 1;
    pp.push_back({1, p[0].second});
    for (int i = 1; i < (int)p.size(); i++) {
      int diff = p[i].first - p[i - 1].first;
      if (diff <= 2) {
        mx += diff;
      } else {
        diff %= 2;
        mx += 2 + diff;
      }
      pp.push_back({mx, p[i].second});
    }
    vector<vector<int>> b(mx + 1, vector<int>(2, 0));
    vector<vector<int>> f(mx + 1, vector<int>(4, 0));
    for (auto [c, r] : pp) {
      b[c][r] = 1;
    }

    f[0][3] = 1;
    for (int i = 1; i <= mx; i++) {
      if (b[i][0] && b[i][1]) {
        f[i][3] |= f[i - 1][3];
      } else {
        if (b[i][0] == 1) {
          f[i][1] |= f[i - 1][3];
          f[i][3] |= f[i - 1][1];
        } else if (b[i][1] == 1) {
          f[i][2] |= f[i - 1][3];
          f[i][3] |= f[i - 1][2];
        } else {
          f[i][3] |= f[i - 1][3];
          f[i][1] |= f[i - 1][2];
          f[i][2] |= f[i - 1][1];
        }
      }
    }
    if (f[mx][3]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
