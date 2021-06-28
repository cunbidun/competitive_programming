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
  string S;
  cin >> S;
  vector<int> mn(S.size() + 1, 1e9);
  vector<int> a;
  int cur = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == '1') {
      cur++;
    } else {
      cur--;
    }
    a.push_back(cur);
  }
  for (int i = (int)S.size() - 1; i >= 0; i--) {
    mn[i] = min(mn[i + 1], a[i]);
  }
  int change = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == '0') {
      change++;
    } else {
      if (change + mn[i] > 0) {
        S[i] = '0';
      }
      change--;
    }
  }
  cout << S << '\n';
}
