/**
 *  author: cunbidun
 *  created: Saturday, 2023-02-11 09:10:53 CST
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
  int N;
  cin >> N;
  vector<array<int, 2>> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0];
    a[i][1] = i;
  }
  sort(a.begin(), a.end());
  vector<int> pos(N);
  for (int i = 0; i < N; i++) {
    pos[a[i][1]] = i;
  }
  int current = 0;
  vector<long long> ans(N);
  int last = 0;
  for (int i = 0; i < N; i++) {
    while (current < N && pos[current] < i) {
      current += 1;
    }
    if (pos[current] == i) {
      ans[current] += 1LL * (a[i][0] - last) * (N - 1 - i + 1);
      last = a[i][0];
    } else {
      ans[current] += a[i][0] - last;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << '\n';
  }
}
