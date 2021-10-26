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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N;
    cin >> N;
    vector<char> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<int> l(N + 1, -1), r(N + 2, 1e9);
    vector<int> f(N + 1, 1e9);
    for (int i = 1; i <= N; i++) {
      l[i] = l[i - 1];
      if (a[i] == '1') {
        l[i] = i;
      }
      if (l[i] != -1) {
        f[i] = min(f[i], i - l[i]);
      }
    }
    for (int i = N; i >= 1; i--) {
      r[i] = r[i + 1];
      if (a[i] == '1') {
        r[i] = i;
      }
      if (r[i] != 1e9) {
        f[i] = min(f[i], r[i] - i);
      }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      ans += f[i];
    }
    cout << ans << '\n';
  }
}
