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
  int N;
  int64_t K, s = 0;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a.begin(), a.end());
  vector<array<int64_t, 2>> l, r;
  for (int i = 1; i < N; i++) {
    l.push_back({i, a[i] - a[i - 1]});
  }
  for (int i = N - 2; i >= 0; i--) {
    r.push_back({N - i - 1, a[i + 1] - a[i]});
  }
  int64_t mx = a.back(), mn = a.front();
  int p = 0;
  for (int i = 0; i < (int)l.size(); i++) {
    while (p < (int)r.size() && l[i][0] > r[p][0] && K >= r[p][0]) {
      int64_t sub = min(K / r[p][0], r[p][1]);
      mx -= sub;
      K -= r[p][0] * sub;
      p++;
    }
    if (K >= l[i][0]) {
      int64_t add = min(K / l[i][0], l[i][1]);
      mn += add;
      K -= l[p][0] * add;
    }
  }
  cout << max(mx - mn, (int64_t)0) << '\n';
}
