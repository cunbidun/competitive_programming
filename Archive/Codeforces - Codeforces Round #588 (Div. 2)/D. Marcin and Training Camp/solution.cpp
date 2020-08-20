#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 7e3 + 5;

int n, ch[N];
ll ans = 0;
pair<ll, ll> a[N];
set<ll> l;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  union_find dsu(N);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }

  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    if (l.find(a[i].first) != l.end()) {
      ch[i] = 1;
    }
    l.insert(a[i].first);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (ch[j] && (a[i].first & a[j].first) == a[i].first) {
        dsu.merge(i, j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ch[dsu.find(i)] == 1) {
      ans += a[i].second;
    }
  }
  cout << ans << "\n";
}