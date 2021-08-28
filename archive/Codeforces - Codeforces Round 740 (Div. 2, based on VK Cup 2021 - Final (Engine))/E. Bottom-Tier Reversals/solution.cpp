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
    int N;
    cin >> N;
    vector<int> a(N + 1);
    int f = 0;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      f |= ((a[i] - i) % 2) != 0;
    }

    vector<int> ans;
    auto re = [&](int l) {
      if (l <= 1) {
        return;
      }
      ans.push_back(l);
      for (int i = 1; i <= l / 2; i++) {
        swap(a[i], a[l - i + 1]);
      }
    };
    if (f) {
      cout << -1 << '\n';
    } else {
      int cur = N - 1;
      while (cur != 0) {
        int pc = 0;
        for (int i = 1; i <= N; i++) {
          if (a[i] == cur) {
            pc = i;
            break;
          }
        }
        int p = 0;
        for (int i = 1; i <= N; i++) {
          if (a[i] == cur + 1) {
            p = i;
            break;
          }
        }
        if (p < pc) {
          re(p);
          re(pc - 1);
          re(pc + 1);
          re(3);
        } else {
          re(p);
          pc = p - pc + 1;
          re(pc - 1);
          re(pc + 1);
          re(3);
        }
        re(cur + 1);
        cur -= 2;
      }
      cout << ans.size() << '\n';
      for (int i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }
}
