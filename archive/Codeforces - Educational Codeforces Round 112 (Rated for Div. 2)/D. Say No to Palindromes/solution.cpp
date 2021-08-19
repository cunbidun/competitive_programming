#include <bits/stdc++.h>

using namespace std;

template <class c>
struct rge { c b, e; };
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
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
  debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int cnt[3][(int)(2e5)][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  string s[3];
  for (int i = 0; i < N; i++) {
    char c;
    cin >> c;
    s[i % 3].push_back(c);
  }
  for (int i = 0; i < min(N, 3); i++) {
    cnt[i][0][s[i][0] - 'a']++;
    for (int j = 1; j < (int)s[i].size(); j++) {
      for (int k = 0; k < 3; k++) {
        cnt[i][j][k] = cnt[i][j - 1][k];
      }
      cnt[i][j][s[i][j] - 'a']++;
    }
  }
  auto get = [&](int id, int c, int l, int r) -> int {
    if (l > r) {
      return 0;
    }
    l /= 3, r /= 3;
    if (l == 0) {
      return cnt[id][r][c];
    } else {
      return cnt[id][r][c] - cnt[id][l - 1][c];
    }
  };
  auto getafter = [](int i, int m) -> int {
    for (;;) {
      if (i % 3 == m) {
        return i;
      }
      i++;
    }
  };

  auto getb4 = [](int i, int m) -> int {
    for (;;) {
      if (abs(i) % 3 == m) {
        return i;
      }
      i--;
    }
  };
  while (Q--) {
    int ans = 1e9;
    int l, r;
    cin >> l >> r;
    l--, r--;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    do {
      int res = 0;
      int c0 = get(0, a[0], getafter(l, 0), getb4(r, 0));
      int c1 = get(1, a[1], getafter(l, 1), getb4(r, 1));
      int c2 = get(2, a[2], getafter(l, 2), getb4(r, 2));
      res = (r - l + 1) - (c0 + c1 + c2);

      ans = min(ans, res);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
  }
}
