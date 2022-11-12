
#include <array>
#include <functional>
#include <iostream>
#include <set>

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
// fenwick_tree
// 1-based index
template <typename T> struct fenwick_tree {
  vector<T> bit;
  int n;
  fenwick_tree() {}
  fenwick_tree(int _n) { init(_n); }
  void init(int _n) { n = _n, bit.assign(n + 1, T{}); }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v, p += p & -p;
    }
  }
  T get(int p) {
    T res{};
    while (p >= 1) {
      res += bit[p], p -= p & -p;
    }
    return res;
  }
  T get(int l, int r) { return (l > r) ? T{} : get(r) - get(l - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, M;
  cin >> H >> W >> M;
  set<array<int, 2>> point;
  int mn_x = W, mn_y = H;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    point.insert({x, y});
    if (x == 1) {
      mn_x = min(mn_x, y);
    }
    if (y == 1) {
      mn_y = min(mn_y, x);
    }
  }
  for (int i = mn_x + 1; i <= W; i++) {
    point.insert({1, i});
  }
  for (int i = mn_y + 1; i <= H; i++) {
    point.insert({i, 1});
  }
  int ans = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      int ch = 0;
      for (int k = 1; k <= i; k++) {
        if (point.find({k, j}) != point.end()) {
          ch += 1;
          break;
        }
      }
      for (int k = 1; k <= j; k++) {
        if (point.find({i, k}) != point.end()) {
          ch += 1;
          break;
        }
      }
      if (ch == 2) {
        ans++;
      }
    }
  }
  cout << H * W - ans << '\n';
}
