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
  long long A1, A2, B1, B2, T1, T2;
  cin >> T1 >> T2;
  cin >> A1 >> A2;
  cin >> B1 >> B2;
  if (A1 * T1 + A2 * T2 == B1 * T1 + B2 * T2) {
    cout << "infinity\n";
    return 0;
  }
  auto s = [](long long n) -> long long {
    if (n == 0) {
      return 0;
    }
    return n / abs(n);
  };
  vector<long long> a, b;
  int lim = 20000;
  for (int i = 1; i <= lim; i++) {
    a.push_back(i * (A1 * T1) + (i - 1) * (A2 * T2));
    a.push_back(i * (A1 * T1) + i * (A2 * T2));
    b.push_back(i * (B1 * T1) + (i - 1) * (B2 * T2));
    b.push_back(i * (B1 * T1) + i * (B2 * T2));
  }
  int res = 0;
  for (int i = 1; i < lim; i++) {
    if (a[i - 1] == b[i - 1]) {
      continue;
    }
    if (s(a[i - 1] - b[i - 1]) * s(a[i] - b[i]) <= 0) {
      res++;
    }
  }
  // debug() << imie(a);
  // debug() << imie(b);
  cout << res << '\n';
}
