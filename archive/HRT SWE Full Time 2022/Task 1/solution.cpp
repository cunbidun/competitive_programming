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

int solution(vector<int> &a, int K) {
  int N = a.size();
  vector<int> mx_l(N), mx_r(N), mn_l(N), mn_r(N);
  mx_l[0] = a[0];
  mx_r[N - 1] = a[N - 1];
  mn_l[0] = a[0];
  mn_r[N - 1] = a[N - 1];
  for (int i = 1; i < N; i++) {
    mn_l[i] = min(mn_l[i - 1], a[i]);
    mx_l[i] = max(mx_l[i - 1], a[i]);
  }
  for (int i = N - 2; i >= 0; i--) {
    mn_r[i] = min(mn_r[i + 1], a[i]);
    mx_r[i] = max(mx_r[i + 1], a[i]);
  }
  // cout << K << '\n';
  // cout << mx_r[N - K - 1] << ' ' << mn_r[N - K - 1] << '\n';
  int ans = min(mx_r[K] - mn_r[K], mx_l[N - K - 1] - mn_l[N - K - 1]);
  // cout << ans << '\n';
  for (int i = 1; i < N - K; i++) {
    int mx = max(mx_l[i - 1], mx_r[i + K]);
    int mn = min(mn_l[i - 1], mn_r[i + K]);
    ans = min(ans, mx - mn);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cout << solution(a, K) << '\n';
}
