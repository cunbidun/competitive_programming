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
  int N;
  long long K;
  cin >> N >> K;

  vector<long long> s(N + 1);
  vector<int> a(N + 2);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  a[N + 1] = 1e9;
  sort(a.begin(), a.end());

  vector<int> nxt(2 * a[N] + 1);
  {
    int p = 1;
    for (int i = 1; i <= a[N]; i++) {
      while (a[p] <= i) {
        p++;
      }
      nxt[i] = p;
    }
  }
  for (int i = a[N] + 1; i <= 2 * a[N]; i++) {
    nxt[i] = N + 1;
  }
  long long ans = 0;
  for (int i = 1; i <= a[N]; i++) {
    int cur = i;
    int p = 1;
    long long ts = 0;
    while (p <= N) {
      if (cur < a[p]) {
        cur = (a[p] + i - 1) / i * i;
      }
      ts += 1LL * (nxt[cur] - p) * cur;
      p = nxt[cur];
    }
    if (ts - s[N] <= K) {
      ans = max(ans, 1LL * i);
    }
  }
  if ((s[N] + K) / N >= a[N]) {
    ans = max(ans, (s[N] + K) / N);
  }
  cout << ans << '\n';
}
