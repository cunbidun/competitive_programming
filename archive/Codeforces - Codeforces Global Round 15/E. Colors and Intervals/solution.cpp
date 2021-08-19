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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N * K + 1);
  vector<array<int, 2>> ans(N + 1);
  for (int i = 1; i <= N * K; i++) {
    cin >> a[i];
  }
  vector<int> d(N + 1);
  int cnt = 0;
  while (cnt < N) {
    vector<int> p(N + 1, -1);
    for (int i = 1; i <= N * K; i++) {
      if (!d[a[i]]) {
        if (p[a[i]] != -1) {
          d[a[i]] = 1;
          ans[a[i]] = {p[a[i]], i};
          p.assign(N + 1, -1);
          cnt++;
          if (cnt == N) {
            break;
          }
        } else {
          p[a[i]] = i;
        }
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i][0] << ' ' << ans[i][1] << '\n';
  }
}
