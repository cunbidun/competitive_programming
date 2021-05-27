#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;

  union_find(int N) {
    dsu_size = N;
    p.assign(N + 1, 0);
    rank.assign(N + 1, 0);
    child.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n;
  union_find dsu(n);
  cin >> q;
  while (q--) {
    int c, u, v;
    cin >> c >> u >> v;
    if (c == 0)
      dsu.merge(u, v);
    else
      cout << dsu.is_same_set(u, v) << "\n";
  }
}
