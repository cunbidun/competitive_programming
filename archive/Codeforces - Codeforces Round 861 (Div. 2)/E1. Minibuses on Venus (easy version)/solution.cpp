/**
 *  author: cunbidun
 *  created: Monday, 2023-09-04 13:17:25 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct mod_int {
  int MOD;
  mod_int(int MOD) { this->MOD = MOD; }
  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }
  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }
  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }
  int pow(int x, int p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }
  int inv(int x) { return pow(x, MOD - 2); }
  int div(int x, int y) { return mul(x, inv(y)); }
};

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

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
  int N, K, M;
  cin >> N >> K >> M;
  mod_int mint(M);
  vector<vector<int>> f(vector<vector<int>>(K * N + 1, vector<int>(K)));
  vector<set<int>> skip(K);

  for (int i = 0; i < K; i++) {
    skip[(i * 2) % K].insert(i);
  }

  map<vector<int>, int> mp;
  for (int i = 0; i < K; i++) {
    if ((int)skip[i].size() != K) {
      f[0][i] = 1;
    }
  }

  for (int it = 1; it <= N; it++) {
    for (int sum = N * (K - 1); sum >= 0; sum--) {
      for (int skip_id = 0; skip_id < K; skip_id++) {
        int og = f[sum][skip_id];
        for (int k = 0; k < K; k++) {
          if (skip[skip_id].find(k) == skip[skip_id].end() && sum >= k) {
            f[sum][skip_id] = mint.add(f[sum][skip_id], f[sum - k][skip_id]);
          }
        }
        f[sum][skip_id] = mint.sub(f[sum][skip_id], og);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < N; i++) {
    ans = mint.mul(ans, K);
  }
  for (int sum = 0; sum <= N * (K - 1); sum++) {
    ans = mint.sub(ans, f[sum][sum % K]);
  }

  cout << ans << '\n';
}
