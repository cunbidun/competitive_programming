/**
 *  author: cunbidun
 *  created: Monday, 2023-03-27 21:26:40 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std
using namespace std;

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
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};

#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct Dinic {
  struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
  };
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }

  void add_edge(int v, int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].u] != -1)
          continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  long long dfs(int v, long long pushed) {
    if (pushed == 0)
      return 0;
    if (v == t)
      return pushed;
    for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  long long flow() {
    long long f = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
        break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)) {
        f += pushed;
      }
    }
    return f;
  }
};

struct BidirectionalMap {
  map<array<int, 2>, int> mp;
  vector<array<int, 2>> r;
  int add_and_get(array<int, 2> x) {
    if (mp.find(x) == mp.end()) {
      mp[x] = mp.size();
      r.push_back(x);
    }
    return mp[x];
  }
  array<int, 2> get_r(int x) { return r[x]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<string> a(N + 1);
  vector<vector<set<array<int, 2>>>> r(N + 1, vector<set<array<int, 2>>>(M + 1, set<array<int, 2>>()));
  for (int i = 0; i <= M; i++) {
    a[0] += "#";
  }
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    a[i] = "#" + a[i];
  }
  for (int x = 1; x <= N; x++) {
    for (int y = 1; y <= M; y++) {
      if (a[x][y] == 'o') {
        vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0));
        yc([&](auto dfs, int i, int j) -> void {
          if (i > N || j > M || a[i][j] == '#' || visited[i][j]) {
            return;
          }
          visited[i][j] = 1;
          r[i][j].insert({x, y});
          dfs(i + 1, j);
          dfs(i, j + 1);
        })(x, y);
      }
    }
  }

  vector<vector<int>> visited(N + 1, vector<int>(M + 1, 0));
  int ans = 0;
  int x = N, y = M;
  while (true) {
    BidirectionalMap mp;
    Dinic F(210, 208, 209);
    set<int> added;
    for (int i = 0;; i++) {
      if (x - i < 1 || y + i > M) {
        break;
      }
      if (a[x - i][y + i] == '#') {
        continue;
      }
      auto id = mp.add_and_get({x - i, y + i});
      int overlap = 0;
      for (auto [c, d] : r[x - i][y + i]) {
        if (!visited[c][d]) {
          if (c == x - i && d == y + i) {
            visited[c][d] = 1;
            overlap = 1;
            continue;
          }
          auto tmp = mp.add_and_get({c, d});
          if (added.find(tmp) == added.end()) {
            F.add_edge(208, tmp, 1);
            // cout << 208 << ' ' << tmp << ' ' << 1 << '\n';
            added.insert(tmp);
          }
          F.add_edge(tmp, id, 1);
        }
      }
      F.add_edge(id, 209, 1 - overlap);
    }
    // cout << x << ' ' << y << '\n';
    // for (auto fe : F.edges) {
    //   if (fe.cap == 1) {
    //     cout << fe.v << ' ' << fe.u << ' ' << fe.cap << '\n';
    //   }
    // }
    // cout << '\n';
    // cout << F.flow() << '\n';
    auto mx = F.flow();
    int cnt = 0;
    for (auto fe : F.edges) {
      if (fe.u < 205 && fe.v < 205 && fe.flow == 1) {
        auto [c, d] = mp.get_r(fe.u);
        auto [u, v] = mp.get_r(fe.v);
        // debug() << imie(c) imie(d);
        // debug() << imie(u) imie(v);
        ans += abs(c - u) + abs(d - v);
        cnt++;
        visited[c][d] = 1;
        visited[u][v] = 1;
      }
    }
    assert(cnt == mx);
    if (x == 1 && y == 1) {
      break;
    }
    if (y > 1) {
      y--;
    } else {
      x--;
    }
  }
  cout << ans << '\n';
}
