#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " 

const int N = 1e5 + 5;
int n, a[N], use[N];
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int p = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      use[i] = 1;
    } else {
      p = i;
    }
    if (a[i] == 1) {
      q.push(i);
    }
  }
  if (p != -1 && a[p] != 1) {
    cout << -1 << "\n";
    return 0;
  }
  vector<ii> ans;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 2) {
      if (q.empty()) {
        cout << -1 << "\n";
        return 0;
      } else {
        int c = -1;
        while (!q.empty()) {
          c = q.front();
          q.pop();
          if (i < c) {
            break;
          }
        }
        if (c < i) {
          cout << -1 << "\n";
          return 0;
        }
        use[i] = 1;
        use[c] = 1;
        ans.push_back({i, i});
        ans.push_back({c, i});
      }
    }
  }
  vi l;
  p = -1;
  for (int i = 1; i <= n; i++) {
    if (!use[i]) {
      if (a[i] == 3) {
        p = i;
      }
      l.push_back(i);
      ans.push_back({i, i});
    }
  }
  int ok = 1;
  if (sz(l) != 0 && a[l[sz(l) - 1]] == 3) {
    ok = 0;
    for (int i = p; i <= n; i++) {
      if (a[i] == 2) {
        ok = 1;
        l.push_back(i);
        break;
      }
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return 0;
  }
  for (int i = 0; i < sz(l); i++) {
    if (a[l[i]] == 3) {
      ans.push_back({l[i + 1], l[i]});
    }
  }
  cout << sz(ans) << "\n";
  for (auto [f, s] : ans) {
    cout << s << " " << f << "\n";
  }
}
