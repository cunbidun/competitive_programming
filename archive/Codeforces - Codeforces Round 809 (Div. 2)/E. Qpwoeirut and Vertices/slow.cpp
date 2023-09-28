#include <array>
#include <assert.h>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

struct dsu {
  vector<int> ds, wt;
  dsu(int n) {
    ds.assign(n, -1);
    wt.assign(n, INT_MAX);
  }
  int find(int i) { return ds[i] < 0 ? i : find(ds[i]); }
  void merge(int i, int j, int weight) {
    i = find(i), j = find(j);
    if (i != j) {
      if (ds[i] > ds[j])
        swap(i, j);
      ds[i] += ds[j], ds[j] = i;
      wt[j] = weight;
    }
  }
  int weight(int i, int j) {
    int w = 0;

    while (i != j) {
      if (wt[i] < wt[j])
        w = wt[i], i = ds[i];
      else
        w = wt[j], j = ds[j];
    }
    return w;
  }
};

struct segtree {
  vector<int> tr;
  int n;
  segtree(vector<int> v) {
    n = v.size();
    tr.resize(n * 2);
    for (int i = 0; i < n; i++)
      tr[n + i] = v[i];
    for (int i = n - 1; i > 0; i--)
      pull(i);
  }
  void pull(int i) { tr[i] = max(tr[i * 2], tr[i * 2 + 1]); }
  int query(int l, int r) {
    int x = 0;

    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1)
        x = max(x, tr[l++]);
      if (~r & 1)
        x = max(x, tr[r--]);
    }
    return x;
  }
};

void run() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  dsu ds(n);
  for (int w = 1; w <= m; w++) {
    int i, j;
    scanf("%d%d", &i, &j), i--, j--;
    ds.merge(i, j, w);
  }

  vector<int> weights(n - 1);
  for (int i = 0; i < n - 1; i++)
    weights[i] = ds.weight(i, i + 1);

  segtree st(weights);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r), l--, r--;
    printf("%d ", l == r ? 0 : st.query(l, r - 1));
  }
  printf("\n");
}

int main() {
  int t = 1;

  scanf("%d", &t);
  while (t--)
    run();
  return 0;
}
