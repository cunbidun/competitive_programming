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
    vector<int> p(N + 1);
    set<int> s;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      s.insert(a[i]);
      p[a[i]] = i;
    }
    cout << s.size() << '\n';

    if ((int)s.size() == N) {
      for (int i = 1; i <= N; i++) {
        cout << a[i] << ' ';
      }
      cout << '\n';
      continue;
    }
    if ((int)s.size() == N - 1) {
      int pos = 0;
      for (int i = 1; i <= N; i++) {
        if (s.find(i) == s.end()) {
          pos = i;
          break;
        }
      }
      p[a[pos]] = pos;

      vector<int> ans(N + 1);
      for (int i = 1; i <= N; i++) {
        ans[p[i]] = i;
      }
      for (int i = 1; i <= N; i++) {
        if (ans[i] == 0) {
          ans[i] = pos;
        }
      }
      for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
      continue;
    }
    set<int> st;
    vector<int> ans(N + 1);
    for (int i = 1; i <= N; i++) {
      ans[p[i]] = i;
      if (s.find(i) == s.end()) {
        st.insert(i);
      }
    }
    // debug() << imie(st);
    deque<int> q;
    for (int i = 1; i <= N; i++) {
      if (ans[i] == 0) {
        auto it = st.find(i);
        if (it == st.end()) {
          q.push_back(i);
        } else {
          q.push_front(i);
        }
      }
    }
    while (!q.empty()) {
      int u = q.front();
      cerr << u << '\n';
      q.pop_front();
      auto it = st.find(u);
      auto next = st.begin();
      if (it == st.begin()) {
        next = it;
        next++;
      }
      ans[u] = *next;
      st.erase(next);
    }
    for (int i = 1; i <= N; i++) {
      assert(ans[i] != i);
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
