#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;

  union_find(int dsu_size) : dsu_size(dsu_size) {
    p.assign(dsu_size + 1, 0);
    rank.assign(dsu_size + 1, 0);
    child.assign(dsu_size + 1, 0);
    for (int i = 1; i <= dsu_size; i++) {
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

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  union_find dsu(m + 1);
  vi l;
  int ans = 1;

  for (int i = 1; i <= n; i++) {
    int k, x1, x2;
    cin >> k;
    if (k == 1) {
      cin >> x1;
      if (!dsu.is_same_set(x1, m + 1)) {
        dsu.merge(x1, m + 1);
        l.push_back(i);
      }
    } else {
      cin >> x1 >> x2;
      if (!dsu.is_same_set(x1, x2)) {
        if (!dsu.is_same_set(x1, m + 1) || !dsu.is_same_set(x2, m + 1)) {
          dsu.merge(x1, x2);
          l.push_back(i);
        }
      }
    }
  }

  for (int i = 1; i <= sz(l); i++) {
    ans = (ans * 2) % MOD;
  }
  cout << ans << " " << sz(l) << "\n";
  for (int i : l) {
    cout << i << " ";
  }
  cout << "\n";
}
