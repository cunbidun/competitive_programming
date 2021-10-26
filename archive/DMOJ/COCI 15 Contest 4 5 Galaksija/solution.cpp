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

struct union_find {
  typedef vector<int> vi;
  vi p, sz;
  int dsu_size;
  union_find(int _n) : p(vi(_n)), sz(vi(_n, 1)), dsu_size(_n) {
    for (int i = 0; i < _n; i++) {
      p[i] = i;
    }
  }
  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
  bool is_same_set(int x, int y) { return find(x) == find(y); }
  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x), y = find(y);
      p[x] = y, sz[y] += sz[x];
    }
  }
  int size(int i) { return sz[find(i)]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 3>> edge;
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edge.push_back({u, v, w});
  }
  vector<int> idx(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> idx[i];
    idx[i]--;
  }
  vector<long long> ans(N);

  union_find dsu(N);

  vector<unordered_map<int, int>> l(N);
  vector<unordered_map<int, int>> cnt(N);

  ans[N - 1] = 0;
  for (int i = 0; i < N; i++) {
    l[i][i] = 0;
    cnt[i][0] = 1;
  }

  long long cur = 0;
  for (int i = N - 2; i >= 0; i--) {
    auto [u, v, w] = edge[idx[i]];
    if (dsu.size(u) > dsu.size(v)) {
      swap(u, v);
    }
    int pu = dsu.find(u);
    int pv = dsu.find(v);
    int xu = l[pu][u]; // xor path from pu to u
    int xv = l[pv][v]; // xor path from pv to v

    for (auto [f, s] : l[pu]) {
      int nx = s ^ xu ^ w ^ xv;
      cur += cnt[pv][nx];
    }

    for (auto [f, s] : l[pu]) {
      int nx = s ^ xu ^ w ^ xv;
      l[pv][f] = nx;
      cnt[pv][nx]++;
    }
    l[u].clear();
    cnt[u].clear();
    dsu.merge(u, v);
    ans[i] = cur;
  }

  for (long long i : ans) {
    cout << i << '\n';
  }
}
