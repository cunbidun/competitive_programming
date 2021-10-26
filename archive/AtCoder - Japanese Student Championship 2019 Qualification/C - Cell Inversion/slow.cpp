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
  string S;
  cin >> N >> S;
  vector<int> a;
  vector<int> o(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    if (S[i] == 'W') {
      o[i] = 0;
    } else {
      o[i] = 1;
    }
    a.push_back(i);
  }
  int ans = 0;
  do {

    int ok = 1;
    vector<int> oo = o;
    for (int i = 0; i < 2 * N; i += 2) {
      if (a[i] > a[i + 1]) {
        ok = 0;
        break;
      }
      for (int j = a[i]; j <= a[i + 1]; j++) {
        oo[j]++;
      }
    }
    for (int i = 0; i < 2 * N; i++) {
      if (oo[i] % 2 == 1) {
        ok = 0;
        break;
      }
    }
    // if (ok) {
    //   debug() << imie(a);
    // }
    ans += ok;
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << '\n';
}
