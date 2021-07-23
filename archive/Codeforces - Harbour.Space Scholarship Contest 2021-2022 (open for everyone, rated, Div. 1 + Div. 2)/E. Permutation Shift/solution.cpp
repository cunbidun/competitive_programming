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

struct union_find {
  typedef vector<int> vi;
  vi p, sz, rank;
  int dsu_size;
  union_find(int _n) : p(vi(_n)), sz(vi(_n, 1)), rank(vi(_n)), dsu_size(_n) {
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
      if (rank[x] > rank[y]) {
        p[y] = x, sz[x] += sz[y];
      } else {
        p[x] = y, sz[y] += sz[x];
        rank[y] += (rank[x] == rank[y]);
      }
    }
  }
  int size(int i) { return sz[find(i)]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    vector<vector<int>> offset(N);
    for (int i = 0; i < N; i++) {
      int o = (i + 1) - a[i];
      if (o < 0) {
        o += N;
      }
      offset[o].push_back(a[i]);
    }
    vector<array<int, 2>> l;
    for (int i = 0; i < N; i++) {
      l.push_back({(int)offset[i].size(), i});
    }
    vector<int> ans;
    sort(l.begin(), l.end(), [](auto A, auto B) { return A[0] > B[0]; });
    for (int i = 0; i < min((int)l.size(), 3); i++) {
      vector<int> b(N);
      for (int j = 1; j <= N; j++) {
        b[(j - 1 + l[i][1]) % N] = j;
      }
      union_find dsu(N);
      for (int j = 0; j < N; j++) {
        dsu.merge(b[j] - 1, a[j] - 1);
      }
      if (N - dsu.dsu_size <= M) {
        ans.push_back(l[i][1]);
      }
    }
    cout << ans.size() << ' ';
    sort(ans.begin(), ans.end());
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
