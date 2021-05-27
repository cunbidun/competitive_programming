#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;

template <typename T> struct fenwick_tree {
  vector<T> bit;
  int n;

  fenwick_tree() {}

  fenwick_tree(int n) {
    this->n = n;
    bit.assign(n + 5, 0);
  }

  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v;
      p += p & -p;
    }
  }
  
  void update(int l, int r, T v) {
    update(l, v);
    update(r + 1, -v);
  }

  T get(int p) {
    T res = 0;
    while (p >= 1) {
      res += bit[p];
      p -= p & -p;
    }
    return res;
  }

  T get(int l, int r) { return get(r) - get(l - 1); }
};

fenwick_tree<ll> bit(N);
int n;
vi a[N];
vector<ii> q[N];
ll ans[N];

void dfs(int u, int l = -1, int lvl = 1) {
  for (ii Q : q[u]) {
    bit.update(lvl, lvl + Q.first, Q.second);
  }
  ans[u] = bit.get(lvl);
  for (int v : a[u]) {
    if (v != l) {
      dfs(v, u, lvl + 1);
    }
  }
  for (ii Q : q[u]) {
    bit.update(lvl, lvl + Q.first, -Q.second);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int v, d, x;
    cin >> v >> d >> x;
    q[v].push_back({d, x});
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}