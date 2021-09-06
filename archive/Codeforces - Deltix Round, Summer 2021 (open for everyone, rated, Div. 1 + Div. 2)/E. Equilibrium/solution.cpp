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

template <typename T, class F = function<T(const T &, const T &)>>
class sparse_table {
public:
  int N;
  vector<vector<T>> st;
  F func;
  sparse_table(const vector<T> &a, const F &f) : func(f) {
    N = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(N);
    st.resize(N, vector<T>(max_log));
    for (int i = 0; i < N; i++) {
      st[i][0] = a[i];
    }
    for (int j = 1; j < max_log; j++) {
      for (int i = 0; i + (1 << (j - 1)) < N; i++) {
        st[i][j] = func(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T get(int l, int r) const {
    assert(0 <= l && l <= r && r <= N - 1);
    int k = log2(r - l + 1);
    return func(st[l][k], st[r - (1 << k) + 1][k]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  typedef long long ll;
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a[i] = x - a[i];
  }
  vector<ll> s(N);
  s[0] = a[0];
  for (int i = 1; i < N; i++) {
    s[i] = s[i - 1] + a[i];
  }
  auto get_sum = [&](int l, int r) -> ll {
    return (l == 0) ? s[r] : s[r] - s[l - 1];
  };
  sparse_table<ll> rmin(s, [](ll x1, ll x2) -> ll { return min(x1, x2); });
  sparse_table<ll> rmax(s, [](ll x1, ll x2) -> ll { return max(x1, x2); });
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    ll pre = (l == 0 ? 0 : s[l - 1]);
    if (rmin.get(l, r) - pre >= 0 && get_sum(l, r) == 0) {
      cout << rmax.get(l, r) - pre << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}
