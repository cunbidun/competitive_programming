#include <bits/stdc++.h>

using namespace std;

template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() {
    cout << endl;
  }
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
  debug &operator<<(const c &) {
    return *this;
  }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 2e9;
  vector<int> a(6);
  for (int &p : a) {
    cin >> p;
  }
  cin >> n;
  vector<int> b(n);
  vector<pair<int, int>> c;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int j : a) {
    for (int i = 0; i < n; i++) {
      c.push_back({b[i] - j, i});
    }
  }
  sort(c.begin(), c.end());
  // debug() << imie(c);
  int p = 0;
  int cnt = 0;
  map<int, int> mp;
  for (int i = 0; i < (int)c.size(); i++) {
    mp[c[i].second]++;
    if (mp[c[i].second] == 1) {
      cnt++;
    }
    while (mp[c[p].second] > 1) {
      mp[c[p].second]--;
      p++;
    }
    if (cnt == n) {
      ans = min(ans, c[i].first - c[p].first);
    }
  }
  cout << ans << '\n';
}
