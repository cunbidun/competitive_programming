/**
 *  author: cunbidun
 *  created: Saturday, 2023-07-22 14:20:20 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
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
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  while (Q--) {
    int K;
    cin >> K;
    vector<int> b = a;
    int current = K;
    int mn = 2e9 + 7;

    for (int i = 0; i < N - 1; i++) {
      if (current > 0) {
        b[i] += current;
        current--;
      }
      mn = min(mn, b[i]);
    }

    if (current > 0 && current % 2 == 1) {
      b[N - 1] += current;
      current--;
    }
    mn = min(mn, b[N - 1]);
    long long num = current / 2;
    long long over = 0;
    for (int i = 0; i < N; i++) {
      over += b[i] - mn;
    }
    num -= over;
    if (num > 0) {
      cout << mn - (num + N - 1) / N;
    } else {
      cout << mn;
    }
    cout << ' ';
  }
  cout << '\n';
}
