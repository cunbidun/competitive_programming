/**
 *  author: cunbidun
 *  created: Saturday, 2023-05-20 11:19:36 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iomanip> // std::setprecision
#include <iostream>
#include <numeric>
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
  vector<int> t(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  vector<int> total, real;
  int cnt = 0;
  vector<array<int, 2>> start_pos, end_pos;
  for (int i = 0; i < N; i++) {
    start_pos.push_back({cnt, v[i]});
    if (i > 0) {
      end_pos.push_back({cnt, v[i - 1]});
    }
    for (int j = 0; j < t[i]; j++) {
      total.push_back(v[i]);
      real.push_back(v[i]);
      cnt += 1;
    }
  }
  total.push_back(0);
  start_pos.push_back({cnt, 0});
  end_pos.push_back({0, 0});

  for (auto [pos, s] : start_pos) {
    for (int i = pos; i >= 0; i--) {
      total[i] = min(total[i], s);
      s += 1;
    }
  }

  for (auto [pos, s] : end_pos) {
    for (int i = pos; i <= cnt; i++) {
      total[i] = min(total[i], s);
      s += 1;
    }
  }
  // for (int i = 0; i < (int)total.size(); i++) {
  //   cout << i << ' ' << total[i] << '\n';
  // }
  double ans = 0;
  for (int i = 1; i <= cnt; i++) {
    if (total[i - 1] == total[i] - 1) {
      ans += (double)total[i - 1] + 0.5;
    } else if (total[i - 1] == total[i] + 1) {
      ans += (double)total[i - 1] - 0.5;
    } else if (total[i - 1] == total[i]) {
      ans += total[i];
      if (real[i - 1] > total[i - 1]) {
        ans += 0.25;
      }
    } else {
      exit(10);
    }
    // if (i == 64) {
    //   cout << ans << '\n';
    // }
  }
  cout << std::setprecision(9) << fixed << ans << "\n";
}
