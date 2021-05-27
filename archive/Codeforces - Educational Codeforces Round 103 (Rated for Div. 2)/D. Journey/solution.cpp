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
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    union_find dsu(2 * (n + 1));
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
        dsu.merge(i + 1, i + (n + 1));
      } else {
        dsu.merge(i, i + 1 + (n + 1));
      }
    }
    for (int i = 0; i < n + 1; i++) {
      cout << dsu.size(i) << " ";
    }
    cout << "\n";
  }
}
