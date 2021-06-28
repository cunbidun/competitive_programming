#include <bits/stdc++.h>

using namespace std;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;
  union_find(int _n) {
    dsu_size = _n;
    p.assign(_n, 0);
    rank.assign(_n, 0);
    child.assign(_n, 0);
    for (int i = 0; i < _n; i++) {
      p[i] = i;
      child[i] = 1;
    }
  }
  int find(int i) {
    return (p[i] == i) ? i : (p[i] = find(p[i]));
  }
  bool is_same_set(int x, int y) {
    return find(x) == find(y);
  }
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
  int size(int i) {
    return child[find(i)];
  }
  int num_components() {
    return dsu_size;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> p(N + 1), q(N + 1), pos(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  for (int i = 1; i <= N; i++) {
    cin >> q[i];
  }
  union_find dsu(N + 1);
  for (int i = 1; i <= N; i++) {
    dsu.merge(p[i], q[i]);
  }
  vector<int> c(N + 1);
  vector<int> mx(N + 1);

  for (int i = 1; i <= N; i++) {
    int r = dsu.find(i);
    mx[r] = max(mx[r], pos[i]);
  }

  int cur = 1;
  for (int i = 1; i <= N; i++) {
    if (cur < i) {
      cur = i;
    }
    while (cur <= mx[dsu.find(p[i])]) {
      mx[dsu.find(p[i])] = max(mx[dsu.find(p[i])], mx[dsu.find(p[cur])]);
      mx[dsu.find(p[cur])] = max(mx[dsu.find(p[i])], mx[dsu.find(p[cur])]);
      dsu.merge(p[i], p[cur]);
      cur++;
    }
  }
  if (dsu.num_components() - 1 < K) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (c[dsu.find(p[i])] == 0) {
      c[dsu.find(p[i])] = ++cnt;
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << (char)('a' + min(K, c[dsu.find(i)]) - 1);
  }
  cout << '\n';

  set<char> s;
  string ans = "a";
  for (int i = 1; i <= N; i++) {
    ans += (char)('a' + min(K, c[dsu.find(i)]) - 1);
    s.insert(ans[i]);
  }
  assert((int)s.size() >= K);
  for (int i = 2; i <= N; i++) {
    assert(ans[p[i - 1]] <= ans[p[i]]);
    assert(ans[q[i - 1]] <= ans[q[i]]);
  }
}
