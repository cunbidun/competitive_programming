#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <class c> struct rge {
  c b, e;
};
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
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> a;
    char current = 'a';
    vector<int> used(N);
    for (int i = N - 1; i >= 0; i--) {
      if (S[i] >= current) {
        a.push_back(i);
        used[i] = 1;
        current = S[i];
      }
    }
    // debug() << imie(a);
    current = 'a';
    int f = 0;
    int p = 0;
    for (int i = 0; i < N; i++) {
      char c = S[i];
      if (used[i]) {
        c = S[a[p]];
        p++;
      }
      if (c < current) {
        f = 1;
        break;
      }
      current = c;
    }
    if (f) {
      cout << -1 << '\n';
    } else {
      int ans = a.size() - 1;
      for (int i = (int)a.size() - 2; i >= 0; i--) {
        if (S[a[i]] == S[a[i + 1]]) {
          ans--;
        } else {
          break;
        }
      }
      cout << ans << '\n';
    }
  }
}
