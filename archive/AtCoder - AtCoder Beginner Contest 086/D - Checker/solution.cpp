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
  int N, K;
  cin >> N >> K;
  vector<vector<array<int, 2>>> cnt(2 * K, vector<array<int, 2>>(K));
  auto sum = [&](int c, int x1, int y1, int x2, int y2) -> int {
    if (max(x1, x2) >= 2 * K || max(y1, y2) >= K) {
      return 0;
    }
    if (x1 == 0 && y1 == 0) {
      return cnt[x2][y2][c];
    }
    if (x1 == 0) {
      return cnt[x2][y2][c] - cnt[x2][y1 - 1][c];
    }
    if (y1 == 0) {
      return cnt[x2][y2][c] - cnt[x1 - 1][y2][c];
    }
    return cnt[x2][y2][c] - cnt[x1 - 1][y2][c] - cnt[x2][y1 - 1][c] +
           cnt[x1 - 1][y1 - 1][c];
  };
  for (int i = 0; i < N; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    int mn = min(x / K, y / K);
    x -= mn * K, y -= mn * K;
    x %= 2 * K;
    y %= 2 * K;
    if (y >= K) {
      y -= K;
      x += K;
    }
    if (c == 'W') {
      cnt[x][y][0]++;
    } else {
      cnt[x][y][1]++;
    }
  }
  for (int i = 1; i < 2 * K; i++) {
    cnt[i][0][0] += cnt[i - 1][0][0];
    cnt[i][0][1] += cnt[i - 1][0][1];
  }
  for (int i = 1; i < K; i++) {
    cnt[0][i][0] += cnt[0][i - 1][0];
    cnt[0][i][1] += cnt[0][i - 1][1];
  }
  for (int i = 1; i < 2 * K; i++) {
    for (int j = 1; j < K; j++) {
      cnt[i][j][0] +=
          cnt[i - 1][j][0] + cnt[i][j - 1][0] - cnt[i - 1][j - 1][0];
      cnt[i][j][1] +=
          cnt[i - 1][j][1] + cnt[i][j - 1][1] - cnt[i - 1][j - 1][1];
    }
  }
  int ans = 0;
  for (int c = 0; c < 2; c++) {
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        int cur = sum(c, 0, 0, i, j) + sum(c, i + 1, j + 1, i + K, K - 1) +
                  sum(c, i + K + 1, 0, 2 * K - 1, j);

        int inverse = sum(1 - c, 0, j + 1, i, K - 1) +
                      sum(1 - c, i + 1, 0, i + K, j) +
                      sum(1 - c, i + K + 1, j + 1, 2 * K - 1, K - 1);
        // cout << c << ' ' << i << ' ' << j << ' ' << cur << ' ' << inverse
        //      << '\n';
        ans = max(ans, cur + inverse);
      }
    }
  }
  cout << ans << '\n';
}
