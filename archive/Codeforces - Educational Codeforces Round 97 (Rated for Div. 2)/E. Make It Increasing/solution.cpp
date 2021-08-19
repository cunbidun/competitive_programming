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

int longest_nondec_subseq(std::vector<int> &v) {
  const int INF = 1000000000;
  int n = v.size();
  vector<int> d(n + 1, INF);
  for (int i = 0; i < n; i++) {
    *upper_bound(d.begin(), d.end(), v[i]) = v[i];
  }
  int r = 0;
  for (int i = 0; i <= n; i++) {
    if (d[i] == INF) {
      r = i;
      break;
    }
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N + 2), b(K + 2);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    a[i] -= i;
  }
  for (int i = 1; i <= K; i++) {
    cin >> b[i];
  }
  for (int i = 2; i <= K; i++) {
    if (a[b[i]] < a[b[i - 1]]) {
      cout << "-1\n";
      return 0;
    }
  }
  int ans = 0;
  a[0] = -1e9;
  b[0] = 0;
  a[N + 1] = 1e9;
  b[K + 1] = N + 1;
  for (int i = 1; i <= K + 1; i++) {
    vector<int> l;
    for (int j = b[i - 1] + 1; j < b[i]; j++) {
      if (a[j] < a[b[i - 1]] || a[j] > a[b[i]]) {
        ans++;
      } else {
        l.push_back(a[j]);
      }
    }
    ans += (int)l.size() - longest_nondec_subseq(l);
  }
  cout << ans << '\n';
}
