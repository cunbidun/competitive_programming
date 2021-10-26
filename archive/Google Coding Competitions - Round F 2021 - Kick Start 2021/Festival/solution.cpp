#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, greater_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

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
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int D, N, K;
    cin >> D >> N >> K;
    vector<array<int, 3>> a;
    for (int i = 0; i < N; i++) {
      int h, s, e;
      cin >> h >> s >> e;
      a.push_back({s, h, 1});
      a.push_back({e + 1, h, -1});
    }
    sort(a.begin(), a.end(), [](auto f, auto s) {
      if (f[0] != s[0]) {
        return f[0] < s[0];
      }
      return f[2] < s[2];
    });
    // debug() << imie(a);
    ordered_set s;

    long long ans = 0, cur = 0;

    for (auto [t, h, e] : a) {
      int kth = -1;
      if ((int)s.size() >= K) {
        kth = *s.find_by_order(K - 1);
      }
      if (e == 1) {
        s.insert(h);
        if (kth == -1) {
          cur += h;
        } else if (h > kth) {
          cur += h - kth;
        }
      } else {
        s.erase(s.upper_bound(h));
        if ((int)s.size() < K) {
          cur -= h;
        } else if (h >= kth) {
          cur -= h;
          kth = *s.find_by_order(K - 1);
          cur += kth;
        }
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}
