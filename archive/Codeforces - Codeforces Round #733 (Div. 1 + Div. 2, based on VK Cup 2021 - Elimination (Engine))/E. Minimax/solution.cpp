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

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int N = (int)s.size();
    vector<int> cnt(30);
    int mn = 1e9;
    int next = 1e9;
    for (int i = 0; i < N; i++) {
      cnt[s[i] - 'a']++;
      mn = min(mn, s[i] - 'a');
    }
    if (cnt[mn] == N || cnt[mn] == 1) {
      sort(s.begin(), s.end());
      cout << s << '\n';
      continue;
    }
    int f = -1;
    for (int i = 0; i < 29; i++) {
      if (cnt[i] == 1) {
        f = i;
        break;
      }
    }

    if (f != -1) {
      cout << (char)(f + 'a');
      cnt[f]--;
      for (int i = 0; i < 29; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << (char)(i + 'a');
        }
      }
      cout << '\n';
      continue;
    }

    vector<int> l;
    for (int i = mn + 1; i < 29; i++) {
      if (cnt[i] != 0) {
        next = min(next, i);
      }
      for (int j = 0; j < cnt[i]; j++) {
        l.push_back(i);
      }
    }
    char cur = (char)(mn + 'a');
    if (cnt[mn] - 2 <= N - cnt[mn]) {
      cout << cur << cur;
      cnt[mn] -= 2;
      for (int i : l) {
        cout << (char)(i + 'a');
        if (cnt[mn] > 0) {
          cout << cur;
          cnt[mn]--;
        }
      }
      cout << '\n';
      continue;
    }
    if (cnt[next] == 1) {
      cout << cur << (char)(next + 'a');
      cnt[mn]--;
      cnt[next]--;
      for (int i = 0; i < 29; i++) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << (char)(i + 'a');
        }
      }
      cout << '\n';
      continue;
    }
    if (cnt[mn] + cnt[next] == N) {
      cout << cur << (char)(next + 'a');
      cnt[mn]--;
      cnt[next]--;
      for (int i = 29; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << (char)(i + 'a');
        }
      }
      cout << '\n';
      continue;
    }

    int after = 1e9;
    for (int i = next + 1; i < 29; i++) {
      if (cnt[i] != 0) {
        after = i;
        break;
      }
    }
    cout << cur << (char)(next + 'a');
    cnt[mn]--;
    cnt[next]--;
    for (int i = 0; i < cnt[mn]; i++) {
      cout << cur;
    }
    cnt[mn] = 0;
    cout << (char)(after + 'a');
    cnt[after]--;
    for (int i = 0; i < 29; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        cout << (char)(i + 'a');
      }
    }
    cout << '\n';
  }
}
