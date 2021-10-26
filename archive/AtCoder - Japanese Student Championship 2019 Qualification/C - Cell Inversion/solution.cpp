#include <bits/stdc++.h>

using namespace std;

template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
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
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  int cnt = 0;
  vector<char> l;
  for (int i = 0; i < 2 * N; i++) {
    if (s[i] == 'B') {
      if (cnt % 2 == 0) {
        l.push_back('L');
        cnt++;
      } else {
        l.push_back('R');
        cnt--;
      }
    } else {
      if (cnt % 2 == 0) {
        l.push_back('R');
        cnt--;
      } else {
        l.push_back('L');
        cnt++;
      }
    }
    if (cnt < 0) {
      cout << 0 << '\n';
      return 0;
    }
  }
  if (cnt != 0) {
    cout << 0 << '\n';
    return 0;
  }
  int MOD = 1e9 + 7;
  cnt = 0;
  int ans = 1;
  for (int i = 0; i < 2 * N; i++) {
    if (l[i] == 'L') {
      cnt++;
    } else {
      ans = (1LL * ans * cnt) % MOD;
      cnt--;
    }
  }
  for (int i = 1; i <= N; i++) {
    ans = (1LL * ans * i) % MOD;
  }
  cout << ans << '\n';
}
