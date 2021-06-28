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
    vector<vector<int>> cnt(3, vector<int>(2));
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
      for (int j = 0; j < (int)s[i].size(); j++) {
        cnt[i][s[i][j] - '0']++;
      }
    }
    vector<int> c0, c1;
    for (int i = 0; i < 3; i++) {
      if (cnt[i][0] >= cnt[i][1]) {
        c0.push_back(i);
      } else {
        c1.push_back(i);
      }
    }
    // debug() << imie(c0);
    int num = 0;
    if (c0.size() < 2) {
      c0 = c1;
      num = 1;
    }
    // cout << num << ' ' << c0[1] << ' ' << c0[2] << '\n';
    auto cal = [](int num, string a, string b) {
      int n = a.size();
      vector<int> la, lb;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] - '0' != num) {
          cnt++;
        } else {
          la.push_back(cnt);
          cnt = 0;
        }
      }
      la.push_back(cnt);
      cnt = 0;
      for (int i = 0; i < n; i++) {
        if (b[i] - '0' != num) {
          cnt++;
        } else {
          lb.push_back(cnt);
          cnt = 0;
        }
      }
      lb.push_back(cnt);
      while (la.size() < lb.size()) {
        la.push_back(0);
      }
      while (lb.size() < la.size()) {
        lb.push_back(0);
      }
      for (int i = 0; i < (int)la.size(); i++) {
        for (int j = 0; j < max(la[i], lb[i]); j++) {
          cout << 1 - num;
        }
        if (i != (int)la.size() - 1) {
          cout << num;
        }
      }
      cout << '\n';
    };
    cal(num, s[c0[0]], s[c0[1]]);
  }
}
