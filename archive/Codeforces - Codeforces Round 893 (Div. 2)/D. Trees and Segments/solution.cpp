/**
 *  author: cunbidun
 *  created: Saturday, 2023-08-19 20:09:58 CDT
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
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N + 2);
    for (int i = 1; i <= N; i++) {
      char x;
      cin >> x;
      a[i] = x - '0';
    }
    a[0] = 1;
    a[N + 1] = 1;
    // fpre[i][j] = max consecutive 1 in prefix i that use at most j changes
    vector<vector<int>> fpre(N + 2, vector<int>(K + 1));
    for (int have = 0; have <= K; have++) {
      int p = 1;
      int cnt = 0;
      for (int i = 1; i <= N; i++) {
        if (a[i] == 0) {
          cnt++;
        }
        while (cnt > have) {
          if (a[p] == 0) {
            cnt--;
          }
          p++;
        }
        // if (i == 4 && have == 0) {
        //   cout << p << '\n';
        // }
        fpre[i][have] = max({fpre[i][have], fpre[i - 1][have], i - p + 1});
      }
    }

    vector<vector<int>> fsuf(N + 2, vector<int>(K + 1));
    for (int have = 0; have <= K; have++) {
      int p = N;
      int cnt = 0;
      for (int i = N; i >= 1; i--) {
        if (a[i] == 0) {
          cnt++;
        }
        while (cnt > have) {
          if (a[p] == 0) {
            cnt--;
          }
          p--;
        }
        fsuf[i][have] = max({fsuf[i][have], fsuf[i + 1][have], p - i + 1});
      }
    }

    // debug() << imie(fpre[4]);
    // debug() << imie(fsuf[2]);

    vector<int> f(N + 1, -1);
    f[0] = fpre[N][K];
    for (int start = 1; start <= N; start++) {
      int cnt = 0;
      for (int end = start; end <= N; end++) {
        if (a[end] == 1) {
          cnt++;
        }
        if (cnt <= K) {
          f[end - start + 1] = max({f[end - start + 1], fpre[start - 1][K - cnt], fsuf[end + 1][K - cnt]});
        } else {
          break;
        }
      }
    }
    // debug() << imie(f);

    for (int f_num = 1; f_num <= N; f_num++) {
      int ans = 0;
      for (int i = 0; i <= N; i++) {
        if (f[i] != -1) {
          ans = max(ans, f_num * i + f[i]);
        }
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
}
