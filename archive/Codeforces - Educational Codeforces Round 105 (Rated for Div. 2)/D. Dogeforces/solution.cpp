#include <bits/stdc++.h>

using namespace std;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;

  union_find(int _n) {
    dsu_size = _n;
    p.assign(_n, 0);
    rank.assign(_n, 0);
    child.assign(_n, 1);
    for (int i = 0; i < _n; i++) {
      p[i] = i;
    }
  }

  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }

  bool is_same_set(int x, int y) { return find(x) == find(y); }

  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x);
      y = find(y);
      if (rank[x] > rank[y]) {
        child[x] += child[y];
        p[y] = x;
      } else {
        p[x] = y;
        child[y] += child[x];
        if (rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }
  }

  int size(int i) { return child[find(i)]; }

  int num_components() { return dsu_size; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  vector<int> s(2 * n + 1);
  vector<int> b(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
    s[i] = a[i][i];
  }
  int cnt = n;
  vector<vector<int>> tree(2 * (n + 1), vector<int>());
  function<int(vector<int>)> solve = [&](vector<int> in) {
    int sz = in.size();
    if (in.size() == 1) {
      return in[0];
    }
    vector<pair<int, int>> v;
    for (int i = 1; i < sz; i++) {
      v.push_back({a[in[0]][in[i]], in[i]});
    }
    sort(v.begin(), v.end());
    vector<pair<int, vector<int>>> segments;
    vector<int> tmp;
    tmp.push_back(v[0].second);
    for (int i = 1; i < (int)v.size(); i++) {
      if (v[i].first == v[i - 1].first) {
        tmp.push_back(v[i].second);
      } else {
        segments.push_back({v[i - 1].first, tmp});
        tmp.clear();
        tmp.push_back(v[i].second);
      }
    }
    segments.push_back({v[(int)v.size() - 1].first, tmp});
    int last = in[0];
    for (auto seg : segments) {
      int next = solve(seg.second);
      int top = ++cnt;
      tree[top].push_back(last);
      tree[top].push_back(next);
      last = top;
      s[top] = seg.first;
    }
    return cnt;
  };

  vector<int> l;
  for (int i = 1; i <= n; i++) {
    l.push_back(i);
  }
  solve(l);
  union_find dsu(5005);
  vector<int> root(cnt + 1, 1);
  for (int i = 1; i <= cnt; i++) {
    for (int j : tree[i]) {
      if (s[i] == s[j]) {
        dsu.merge(i, j);
      }
      root[j] = 0;
    }
  }
  vector<set<int>> ftree(cnt + 1, set<int>());
  int r = -1;
  for (int i = 1; i <= cnt; i++) {
    for (int j : tree[i]) {
      if (!dsu.is_same_set(i, j)) {
        ftree[dsu.find(i)].insert(dsu.find(j));
      }
    }
    if (root[i] == 1) {
      r = i;
    }
  }
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[i] = i;
  }
  for (int i = 1; i <= cnt; i++) {
    if (ftree[i].size() != 0) {
      mp[i] = size(mp) + 1;
    }
  }
  cout << mp.size() << '\n';
  for (int i = 1; i <= cnt; i++) {
    if (mp.find(i) != mp.end()) {
      cout << s[i] << ' ';
    }
  }
  cout << '\n';
  cout << mp[dsu.find(r)] << '\n';
  for (int i = 1; i <= cnt; i++) {
    for (int j : ftree[i]) {
      cout << mp[j] << ' ' << mp[i] << '\n';
    }
  }
}
