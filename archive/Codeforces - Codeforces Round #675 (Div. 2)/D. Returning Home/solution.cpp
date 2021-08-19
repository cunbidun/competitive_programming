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
  int N, M;
  cin >> N >> M;
  struct point {
    long long x, y;
    int id;
  };
  vector<point> a(M + 1);
  point s, f;
  cin >> s.x >> s.y >> f.x >> f.y;
  a[0] = s;
  for (int i = 1; i <= M; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 0; i <= M; i++) {
    a[i].id = i;
  }
  vector<vector<array<long long, 2>>> g(M + 1);
  sort(a.begin(), a.end(), [](auto A, auto B) { return A.x < B.x; });
  for (int i = 1; i <= M; i++) {
    int d = a[i].x - a[i - 1].x;
    g[a[i].id].push_back({d, a[i - 1].id});
    g[a[i - 1].id].push_back({d, a[i].id});
  }
  sort(a.begin(), a.end(), [](auto A, auto B) { return A.y < B.y; });
  for (int i = 1; i <= M; i++) {
    int d = a[i].y - a[i - 1].y;
    g[a[i].id].push_back({d, a[i - 1].id});
    g[a[i - 1].id].push_back({d, a[i].id});
  }

  vector<int> d(M + 1, 2e9 + 7);
  auto dijkstra = [&](int s) {
    d[s] = 0;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
      int u = pq.top()[1];
      long long du = pq.top()[0];
      pq.pop();
      if (du > d[u]) {
        continue;
      }
      for (auto p : g[u]) {
        int v = p[1];
        long long uv = p[0];
        if (d[u] + uv < d[v]) {
          d[v] = d[u] + uv;
          pq.push({d[v], v});
        }
      }
    }
  };
  dijkstra(0);
  long long ans = 2e9 + 7;
  for (int i = 0; i <= M; i++) {
    ans = min(ans, abs(f.x - a[i].x) + abs(f.y - a[i].y) + d[a[i].id]);
  }
  cout << ans << '\n';
}
