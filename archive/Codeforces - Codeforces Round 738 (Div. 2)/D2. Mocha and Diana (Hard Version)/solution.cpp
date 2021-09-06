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
  int N, M1, M2;
  cin >> N >> M1 >> M2;
  union_find ad(N), bd(N);
  for (int i = 0; i < M1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ad.merge(u, v);
  }
  for (int i = 0; i < M2; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    bd.merge(u, v);
  }

  int r = 0;
  vector<array<int, 2>> ans;
  for (int i = 0; i < N; i++) {
    if (!ad.is_same_set(i, r) && !bd.is_same_set(i, r)) {
      ans.push_back({i, r});
      ad.merge(i, r);
      bd.merge(i, r);
    }
  }
  set<int> sa, sb;
  for (int i = 0; i < N; i++) {
    if (!ad.is_same_set(r, i)) {
      sa.insert(ad.find(i));
    }
    if (!bd.is_same_set(r, i)) {
      sb.insert(bd.find(i));
    }
  }
  vector<int> la(sa.begin(), sa.end());
  vector<int> lb(sb.begin(), sb.end());
  for (int i = 0; i < (int)min(sa.size(), sb.size()); i++) {
    ans.push_back({la[i], lb[i]});
    ad.merge(la[i], lb[i]);
    bd.merge(la[i], lb[i]);
  }

  cout << ans.size() << '\n';
  for (auto [f, s] : ans) {
    cout << f + 1 << ' ' << s + 1 << '\n';
  }
}
