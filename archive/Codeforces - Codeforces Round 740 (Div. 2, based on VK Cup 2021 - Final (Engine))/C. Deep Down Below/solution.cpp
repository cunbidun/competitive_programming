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

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) {
      int K;
      cin >> K;
      a[i][1] = K;
      int mx = 0;
      for (int j = 0; j < K; j++) {
        int x;
        cin >> x;
        x -= j;
        mx = max(mx, x + 1);
      }
      a[i][0] = mx;
    }
    // debug() << imie(a);
    sort(a.begin(), a.end());
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
      if (cur < a[i][0]) {
        ans += a[i][0] - cur;
        cur = a[i][0];
      }
      cur += a[i][1];
    }
    cout << ans << '\n';
  }
}
