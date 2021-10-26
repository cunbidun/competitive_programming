
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
    int N, Q;
    cin >> N >> Q;
    vector<int> s(N + 1);
    string S;
    cin >> S;
    S = ' ' + S;
    for (int i = 1; i <= N; i++) {
      char c = S[i];
      s[i] = s[i - 1];
      if (c == '+') {
        if (i % 2) {
          s[i]++;
        } else {
          s[i]--;
        }
      } else {
        if (i % 2) {
          s[i]--;
        } else {
          s[i]++;
        }
      }
    }
    auto cal = [&](int l, int r, int m) -> int {
      return s[m - 1] - s[l - 1] + -(s[r] - s[m]);
    };
    auto sign = [&](int x) { return (x > 0) ? 1 : -1; };
    while (Q--) {
      int l, r;
      cin >> l >> r;
      if (s[r] - s[l - 1] == 0) {
        cout << 0 << '\n';
        continue;
      }
      vector<int> ans;
      if ((r - l + 1) % 2 == 0) {
        ans.push_back(r);
        r--;
      }
      if (cal(l, r, l) == 0) {
        ans.push_back(l);
      } else if (cal(l, r, r) == 0) {
        ans.push_back(r);
      } else {
        int lo = l + 1, hi = r - 1;
        while (lo != hi) {
          int m = (lo + hi) / 2;
          if (cal(l, r, m) == 0) {
            lo = m;
            break;
          }
          if (sign(cal(l, r, m)) == sign(cal(l, r, l))) {
            lo = m + 1;
          } else {
            hi = m - 1;
          }
        }
        ans.push_back(lo);
      }
      cout << ans.size() << '\n';
      for (int i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }
}
