/**
 *  author: cunbidun
 *  created: Wednesday, 2023-03-22 21:28:39 CDT
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
  string A;
  cin >> A;
  A = '*' + A + '*';
  int N = A.size();
  vector<vector<int>> next(N, vector<int>(26, N - 1));
  for (int i = N - 3; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      next[i][j] = next[i + 1][j];
    }
    next[i][A[i + 1] - 'a'] = i + 1;
  }
  // cout << A << '\n';
  vector<int> f(N);
  f[N - 1] = 0;
  for (int i = N - 2; i >= 0; i--) {
    int mn = 1e9;
    for (int j = 0; j < 26; j++) {
      mn = min(mn, f[next[i][j]]);
    }
    f[i] = mn + 1;
  }
  string ans = "";
  int i = 0;
  while (i < N - 1) {
    int pos = -1;
    int mn = 1e9;
    for (int j = 0; j < 26; j++) {
      if (mn > f[next[i][j]]) {
        mn = f[next[i][j]];
        pos = j;
      }
    }
    ans += (char)('a' + pos);
    i = next[i][pos];
  }
  cout << ans << '\n';
}
