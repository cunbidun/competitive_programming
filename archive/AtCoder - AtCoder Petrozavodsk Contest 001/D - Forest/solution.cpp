#include <bits/stdc++.h>

using namespace std;

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
  int N, M;
  cin >> N >> M;
  vector<array<int, 2>> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0];
    a[i][1] = i;
  }
  union_find dsu(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    dsu.merge(u, v);
  }
  if (dsu.dsu_size == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (N < (2 * (dsu.dsu_size - 1))) {
    cout << "Impossible\n";
    return 0;
  }
  sort(a.begin(), a.end());
  vector<int> cnt(N);
  vector<int> ch(N);
  long long ans = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if ((++cnt[dsu.find(a[i][1])]) == 1) {
      ch[a[i][1]] = 1;
      ans += a[i][0];
      count++;
    }
  }
  for (int i = 0; i < N; i++) {
    if (count == 2 * (dsu.dsu_size - 1)) {
      break;
    }
    if (!ch[a[i][1]]) {
      ans += a[i][0];
      count++;
    }
  }
  cout << ans << '\n';
}
