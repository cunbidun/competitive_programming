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
    int N;
    cin >> N;
    vector<int> a(N);
    {
      int cnt = 0;
      for (int i = 0; i < N; i++) {
        cin >> a[i];
        cnt += a[i];
      }
      if (cnt % 2 != 0) {
        cout << "NO\n";
        continue;
      }
    }
    vector<int> ans;
    {
      int cnt = 0;
      for (int i = 0; i < N; i++) {
        if (a[i] == 0) {
          if (cnt % 2 == 1) {
            if (i + 1 < N) {
              ans.push_back(i - 1);
              if (a[i + 1] == 0) {
                a[i] = 1;
                a[i + 1] = 1;
                cnt++;
              } else {
                a[i - 1] = 0;
                a[i + 1] = 0;
                cnt = 0;
              }
            }
          } else {
            cnt = 0;
          }
        } else {
          cnt++;
        }
      }
    }
    int p = -1;
    for (int i = 0; i < N; i++) {
      if (a[i] == 0) {
        p = i;
        break;
      }
    }
    if (p == -1) {
      cout << "NO\n";
      continue;
    }
    // debug() << imie(a) << imie(p);
    for (int i = p; i + 2 < N; i++) {
      if (a[i + 1] == 1 && a[i + 2] == 1) {
        ans.push_back(i);
        a[i + 1] = 0;
        a[i + 2] = 0;
      }
    }
    for (int i = p; i - 2 >= 0; i--) {
      if (a[i - 2] == 1 && a[i - 1] == 1) {
        ans.push_back(i - 2);
        a[i - 1] = 0;
        a[i - 2] = 0;
      }
    }
    assert(*max_element(a.begin(), a.end()) == 0);
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
