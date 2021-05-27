#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MOD = 998244353;
int n, k, a[55][55];
int uc[55], ur[55];

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
} dc(50), dr(50);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int ch = 1;
      for (int l = 1; l <= n; l++) {
        if (a[i][l] + a[j][l] > k) {
          ch = 0;
        }
      }
      if (ch == 1) {
        dr.merge(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int ch = 1;
      for (int l = 1; l <= n; l++) {
        if (a[l][i] + a[l][j] > k) {
          ch = 0;
        }
      }
      if (ch == 1) {
        dc.merge(i, j);
      }
    }
  }

  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    if (ur[dr.find(i)] == 1) {
      continue;
    }
    ur[dr.find(i)] = 1;
    for (int j = 1; j <= dr.size(i); j++) {
      ans = (ans * j) % MOD;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (uc[dc.find(i)] == 1) {
      continue;
    }
    uc[dc.find(i)] = 1;
    for (int j = 1; j <= dc.size(i); j++) {
      ans = (ans * j) % MOD;
    }
  }
  cout << ans << "\n";
}