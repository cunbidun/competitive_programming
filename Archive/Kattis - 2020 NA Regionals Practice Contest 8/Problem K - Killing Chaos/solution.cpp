#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

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
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
const int N = 1e5 + 5;

int n, s[N], a[N], l[N];
set<ii> st;

ll cal(ll x) { return ((x + 9) / 10) * 10; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
  }
  st.insert({1, n});
  ll ans = cal(s[n]);
  ll os = cal(s[n]);
  for (int i = 1; i <= n; i++) {
    auto it = st.upper_bound({l[i], 0});
    it--;
    int low = it->first, high = it->second;
    os -= cal(s[high] - s[low - 1]);
    st.erase(it);
    if (l[i] != low) {
      os += cal(s[l[i] - 1] - s[low - 1]);
      st.insert({low, l[i] - 1});
    }
    if (l[i] != high) {
      os += cal(s[high] - s[l[i]]);
      st.insert({l[i] + 1, high});
    }
    ans = max(ans, 1LL * os * (int)st.size());
  }
  cout << ans << '\n';
}
