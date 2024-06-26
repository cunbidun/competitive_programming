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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<array<int, 2>> b(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> b[i][0];
      b[i][1] = i;
    }
    sort(b.begin(), b.end());
    vector<int> mn(N);
    mn[N - 1] = b[N - 1][1];
    for (int i = N - 2; i >= 0; i--) {
      mn[i] = min(mn[i + 1], b[i][1]);
    }
    // debug() << imie(mn);
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
      ans = min(ans, i + mn[a[i] / 2]);
    }
    cout << ans << '\n';
  }
}
