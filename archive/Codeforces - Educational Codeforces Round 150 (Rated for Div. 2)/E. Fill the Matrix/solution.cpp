/**
 *  author: cunbidun
 *  created: Monday, 2023-08-07 22:03:35 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <stack>
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
  int T;
  cin >> T;
  while (T--) {
    int N;
    long long M;
    cin >> N;
    vector<int> a(N + 2);
    a[0] = N;
    a[N + 1] = N;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    cin >> M;
    stack<array<int, 2>> current;
    current.push({a[0], 0});
    vector<long long> sticks(N + 1);
    for (int i = 1; i <= N + 1; i++) {
      int last = 0;
      while (!current.empty()) {
        auto [x, p] = current.top();
        if (x > a[i]) {
          break;
        }
        auto len = i - p - 1;
        auto num = x - last;
        // if (len != 0) {
        //   cout << i << ' ' << len << ' ' << num << '\n';
        // }
        last = x;
        sticks[len] += num;
        current.pop();
      }

      if (last < a[i] && !current.empty()) {
        auto [x, p] = current.top();

        assert(x > a[i]);
        auto len = i - p - 1;
        auto num = a[i] - last;
        // if (len != 0) {
        //   cout << i << ' ' << len << ' ' << num << '\n';
        // }
        last = x;
        sticks[len] += num;
      }
      current.push({a[i], i});
    }
    debug() << imie(sticks);
    long long lost = 0;
    long long tmp = M;
    for (int i = N; i > 0; i--) {
      long long mx = (tmp + i - 1) / i;
      long long used = min(mx, sticks[i]);
      lost += used;
      tmp -= used * i;
      if (tmp <= 0) {
        break;
      }
    }
    assert(tmp <= 0);
    // cout << tmp << '\n';
    cout << M - lost << '\n';
  }
}
