/**
 *  author: cunbidun
 *  created: Sunday, 2023-08-27 13:55:37 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
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
  long long CAP = 2e7;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> candidate;
    set<int> in;
    for (int i = 0; i < N; i++) {
      long long x;
      cin >> x;
      for (int j = 0; j < (int)candidate.size(); j++) {
        candidate[j] = candidate[j] / gcd(candidate[j], x) * x;
      }
      candidate.push_back(x);
      set<int> in_new;
      vector<long long> new_candidate;
      for (int j = (int)candidate.size() - 1; j >= 0; j--) {
        long long num = candidate[j];
        if (num <= CAP && in_new.find(num) == in_new.end()) {
          in_new.insert(num);
          new_candidate.push_back(num);
        }
      }
      reverse(new_candidate.begin(), new_candidate.end());
      candidate = new_candidate;
      debug() << imie(candidate);
      for (auto j : candidate) {
        in.insert(j);
      }
    }
    int ans;
    for (ans = 1;; ans++) {
      if (in.find(ans) == in.end()) {
        break;
      }
    }
    cout << ans << '\n';
  }
}
