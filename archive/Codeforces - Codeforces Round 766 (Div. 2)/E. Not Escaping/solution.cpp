#include <bits/stdc++.h>

#define ll long long
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
  ll INF = 1e18;
  int T;
  cin >> T;
  while (T--) {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> cost(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> cost[i];
    }
    vector<vector<int>> ir(N + 1);
    vector<vector<array<int, 4>>> l(N + 1);
    map<array<int, 2>, ll> dis;
    ir[1].push_back(1);
    ir[N].push_back(M);
    dis[{1, 1}] = 0;
    for (int i = 1; i <= K; i++) {
      int a, b, c, d, h;
      cin >> a >> b >> c >> d >> h;
      ir[a].push_back(b);
      ir[c].push_back(d);
      l[c].push_back({d, a, b, h}); // 1 means end of the leadder
    }
    for (int i = 1; i <= N; i++) {
      sort(ir[i].begin(), ir[i].end());
    }
    auto get = [&](int i, int j) -> ll {
      auto it = dis.find({i, j});
      if (it == dis.end()) {
        return INF;
      }
      return it->second;
    };
    for (int i = 1; i <= N; i++) {
      if (ir[i].empty()) {
        continue;
      }
      for (auto [j, sf, sr, h] : l[i]) {
        ll val = get(sf, sr);
        if (val != INF) {
          auto it = dis.find({i, j});
          if (it == dis.end() || it->second > val - h) {
            dis[{i, j}] = val - h;
          }
        }
      }

      // from the left
      for (int idx = 1; idx < (int)ir[i].size(); idx++) {
        int j = ir[i][idx];
        int pj = ir[i][idx - 1];
        ll val = get(i, pj);
        if (val != INF) {
          ll n = val + cost[i] * (j - pj);
          auto it = dis.find({i, j});
          if (it == dis.end() || it->second > n) {
            dis[{i, j}] = n;
          }
        }
      }

      // from the right
      for (int idx = (int)ir[i].size() - 2; idx >= 0; idx--) {
        int j = ir[i][idx];
        int pj = ir[i][idx + 1];
        ll val = get(i, pj);
        if (val != INF) {
          ll n = val + cost[i] * (pj - j);
          auto it = dis.find({i, j});
          if (it == dis.end() || it->second > n) {
            dis[{i, j}] = n;
          }
        }
      }
    }
    ll val = get(N, M);
    if (val == INF) {
      cout << "NO ESCAPE" << '\n';
    } else {
      cout << val << '\n';
    }
  }
}
