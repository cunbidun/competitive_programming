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
    int N, M, K;
    cin >> N >> M >> K;
    set<int> h, v;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      v.insert(x);
    }
    for (int i = 0; i < M; i++) {
      int y;
      cin >> y;
      h.insert(y);
    }
    map<int, vector<int>> hm;
    map<int, vector<int>> vm;
    vector<int> hp, vp;
    vector<array<int, 3>> p;
    for (int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;
      p.push_back({x, y, i + 1});
      if (v.find(x) != v.end()) {
        vm[x].push_back(y);
      }
      if (h.find(y) != v.end()) {
        hm[y].push_back(x);
      }
      vp.push_back(y);
      hp.push_back(x);
    }
    for (int x : v) {
      sort(vm[x].begin(), vm[x].end());
    }
    for (int y : h) {
      sort(hm[y].begin(), hm[y].end());
    }
    sort(hp.begin(), hp.end());
    sort(vp.begin(), vp.end());
    long long ans = 0;
    for (auto [x, y, i] : p) {
      long long cnt = 0;
      int l = *(--v.upper_bound(x));
      int r = *(v.lower_bound(x));
      int d = *(--h.upper_bound(y));
      int u = *(h.lower_bound(y));

      if (l == r && u == d) {
        continue;
      }
      if (u == d) {
        cnt += hp.end() - lower_bound(hp.begin(), hp.end(), r);
        cnt += upper_bound(hp.begin(), hp.end(), l) - hp.begin();
        int ex = (--lower_bound(hm[u].begin(), hm[u].end(), r)) -
                 (upper_bound(hm[u].begin(), hm[u].end(), l)) + 1;
        cnt += ex;
      } else {
        cnt += upper_bound(vp.begin(), vp.end(), d) - vp.begin();
        cnt += vp.end() - lower_bound(vp.begin(), vp.end(), u);
        int ex = (--lower_bound(vm[l].begin(), vm[l].end(), u)) -
                 (upper_bound(vm[l].begin(), vm[l].end(), d)) + 1;
        cnt += ex;
      }
      ans += K - cnt;
    }
    cout << ans / 2 << '\n';
  }
}
