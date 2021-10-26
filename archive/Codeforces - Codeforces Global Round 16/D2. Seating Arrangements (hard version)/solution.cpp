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
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> a(N * M + 1);
    for (int i = 1; i <= N * M; i++) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin(), a.end(), [](auto f, auto s) {
      if (f[0] != s[0]) {
        return f[0] < s[0];
      }
      return f[1] < s[1];
    });
    for (int i = 1; i <= N; i++) {
      int cnt = 1;
      int last = M;
      for (int j = M - 1; j >= 1; j--) {
        int cur = M * (i - 1) + j;
        if (a[cur][0] == a[cur + 1][0]) {
          cnt++;
        } else {
          for (int k = cur + 1; k <= cur + cnt; k++) {
            a[k][2] = M * (i - 1) + last - (k - (cur + 1));
          }
          last -= cnt;
          cnt = 1;
        }
      }
      int cur = M * (i - 1);
      for (int k = cur + 1; k <= cur + cnt; k++) {
        a[k][2] = M * (i - 1) + last - (k - (cur + 1));
      }
      last -= cnt;
    }
    sort(a.begin(), a.end(), [](auto f, auto s) { return f[1] < s[1]; });
    vector<vector<int>> ch(N + 1, vector<int>(M + 1));
    int ans = 0;
    for (int i = 1; i <= N * M; i++) {
      int x = (a[i][2] + M - 1) / M;
      int y = a[i][2] % M;
      if (y == 0) {
        y = M;
      }
      for (int j = 1; j <= y; j++) {
        ans += ch[x][j];
      }
      ch[x][y] = 1;
    }
    cout << ans << '\n';
  }
}
