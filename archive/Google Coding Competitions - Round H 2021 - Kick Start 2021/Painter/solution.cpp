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
    vector<set<int>> L(N);
    for (int i = 0; i < N; i++) {
      char c;
      cin >> c;
      if (c == 'R' || c == 'O' || c == 'P' || c == 'A') {
        L[i].insert(0);
      }
      if (c == 'Y' || c == 'O' || c == 'G' || c == 'A') {
        L[i].insert(1);
      }
      if (c == 'B' || c == 'P' || c == 'G' || c == 'A') {
        L[i].insert(2);
      }
    }
    // debug() << imie(L);
    int ans = 0;
    for (int c = 0; c < 3; c++) {
      int cnt = L[0].find(c) != L[0].end();
      for (int i = 1; i < N; i++) {
        if (L[i].find(c) != L[i].end() && L[i - 1].find(c) == L[i - 1].end()) {
          cnt++;
        }
      }
      ans += cnt;
    }
    cout << ans << '\n';
  }
}
