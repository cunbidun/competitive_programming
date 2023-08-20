/**
 *  author: cunbidun
 *  created: Monday, 2023-07-24 23:30:06 CDT
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
  using ll = long long;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N + 1), cold(K + 1), hot(K + 1), last_pos(K + 1), prev(N + 1, 0);
    vector<ll> s(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      prev[i] = last_pos[a[i]];
      last_pos[a[i]] = i;
    }
    for (int i = 1; i <= K; i++) {
      cin >> cold[i];
    }
    for (int i = 1; i <= K; i++) {
      cin >> hot[i];
    }
    for (int i = 1; i <= N; i++) {
      s[i] = s[i - 1] + ((a[i] == a[i - 1]) ? hot[a[i]] : cold[a[i]]);
    }
    vector<ll> f(N + 1, 1e18);
    f[0] = 0;
    for (int i = 1; i <= N; i++) {
      int p = prev[i];
      f[i] = f[i - 1] + cold[a[i]];
      if (p != 0) {
        if (p == i - 1) {
          f[i] = f[i - 1] + hot[a[i]];
          continue;
        }
        ll sum = 0;
        if (p + 1 < i) {
          sum = s[i - 1] - s[p + 1];
        }
        f[i] = min(f[i], f[p + 1] + sum + hot[a[i]]);
      }
    }
    cout << f[N] << '\n';
  }
}
