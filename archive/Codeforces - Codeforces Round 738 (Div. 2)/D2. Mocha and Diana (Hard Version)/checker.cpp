#include "testlib.h"

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

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  if (ans.seekEof()) {
    quitf(_wa, "emtpy output");
  }
  int jans = ans.readInt();
  int pans = ouf.readInt();
  if (jans == pans) {
    int N = inf.readInt();
    int M1 = inf.readInt();
    int M2 = inf.readInt();
    union_find ad(N), bd(N);
    for (int i = 0; i < M1; i++) {
      int u = inf.readInt() - 1, v = inf.readInt() - 1;
      ad.merge(u, v);
    }
    for (int i = 0; i < M2; i++) {
      int u = inf.readInt() - 1, v = inf.readInt() - 1;
      bd.merge(u, v);
    }
    string s = "";
    for (int i = 0; i < jans; i++) {
      int u = ouf.readInt() - 1, v = ouf.readInt() - 1;
      s += to_string(u);
      s += to_string(v);
      if (!ad.is_same_set(u, v) && !bd.is_same_set(u, v)) {
        ad.merge(u, v);
        bd.merge(u, v);
      } else {
        quitf(_wa, "output is not a forest");
      }
    }
    quitf(_ok, "passed");
  } else {
    quitf(_wa, "output different");
  }
}
