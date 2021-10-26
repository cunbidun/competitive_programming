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
  long long T1, T2;
  cin >> T1 >> T2;
  long long A1, A2, B1, B2;
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
  if (s((A1 - B1) * T1) * s((A2 - B2) * T2 + (A1 - B1) * T1) > 0) {
    cout << 0 << '\n';
    return 0;
  }
  if (A1 < B1) {
    swap(A1, B1);
    swap(A2, B2);
  }
  long long ans = ((B2 - A2) * T2 / ((B2 - A2) * T2 + (B1 - A1) * T1)) * 2 - 1;

  if ((B2 - A2) * T2 % ((B2 - A2) * T2 + (B1 - A1) * T1) == 0) {
    ans--;
  }
  cout << ans << '\n';
}
