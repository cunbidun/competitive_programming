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
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<array<int, 2>> a;
    vector<int> used(2 * N + 1);
    for (int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;
      used[x] = 1;
      used[y] = 1;
      if (x > y) {
        swap(x, y);
      }
      a.push_back({x, y});
    }
    while ((int)a.size() < N) {
      vector<int> l;
      for (int i = 1; i <= 2 * N; i++) {
        if (!used[i]) {
          l.push_back(i);
        }
      }
      int x = l[0];
      int y = l[l.size() / 2];
      used[x] = 1;
      used[y] = 1;
      if (x > y) {
        swap(x, y);
      }
      a.push_back({x, y});
    }
    // debug() << imie(a);
    auto inside = [&](int i, int j, int k) -> bool {
      return (i < k && k < j);
    };
    auto check = [&](int i, int j) -> bool {
      if (inside(a[i][0], a[i][1], a[j][0]) && !inside(a[i][0], a[i][1], a[j][1])) {
        return true;
      }
      if (!inside(a[i][0], a[i][1], a[j][0]) && inside(a[i][0], a[i][1], a[j][1])) {
        return true;
      }
      return false;
    };
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        ans += check(i, j);
      }
    }
    // cout << check(0, 1);
    cout << ans << '\n';
  }
}
