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

class PalindromeMatrixDiv2 {
public:
  int minChange(vector<string> A, int rowCount, int columnCount) {
    int n = A.size();
    int m = A[0].size();
    int ans = 100;
    for (int mask1 = 0; mask1 < (1 << n); mask1++) {
      if (__builtin_popcount(mask1) == rowCount) {
        for (int mask2 = 0; mask2 < (1 << m); mask2++) {
          if (__builtin_popcount(mask2) == columnCount) {
            set<int> r, c;
            for (int i = 0; i < n; i++) {
              if ((mask1 >> i) & 1) {
                r.insert(i);
              }
            }
            for (int i = 0; i < m; i++) {
              if ((mask2 >> i) & 1) {
                c.insert(i);
              }
            }
            // for (int i : r) {
            //   cout << i << ' ';
            // }
            // cout << '\n';
            // for (int i : c) {
            //   cout << i << ' ';
            // }
            // cout << '\n';
            int res = 0;
            union_find dsu(65);
            for (int i : r) {
              for (int j = 0; j < m / 2; j++) {
                // cout << i * m + j << ' ' << i * m + m - j - 1 << '\n';
                dsu.merge(i * m + j, i * m + m - j - 1);
              }
            }
            for (int j : c) {
              for (int i = 0; i < n / 2; i++) {
                // cout << i * m + j << ' ' << (n - i - 1) * n + j << '\n';
                dsu.merge(i * m + j, (n - i - 1) * m + j);
              }
            }
            vector<int> cnt(65);
            for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                if (r.find(i) != r.end() || c.find(j) != c.end()) {
                  cnt[dsu.find(i * m + j)] += A[i][j] - '0';
                }
              }
            }
            for (int i = 0; i < n; i++) {
              for (int j = 0; j < m; j++) {
                if (r.find(i) != r.end() || c.find(j) != c.end()) {
                  if (dsu.find(i * m + j) == i * m + j) {
                    // cout << i * m + j << '\n';
                    res += min(cnt[i * m + j], dsu.size(i * m + j) - cnt[i * m + j]);
                  }
                }
              }
            }
            // cout << res << '\n';
            ans = min(ans, res);
            // cout << '\n';
          }
        }
      }
    }
    cout << ans << '\n';
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  PalindromeMatrixDiv2 m;
  int n;
  cin >> n;
  vector<string> s;
  while (n--) {
    string x;
    cin >> x;
    s.push_back(x);
  }
  int c, r;
  cin >> r >> c;
  m.minChange(s, r, c);
}
