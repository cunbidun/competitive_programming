#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, q, cnt = 0, a[2 * N], p[N], in[N], out[N];
vi adj[N];
int seg[8 * N], lazy[8 * N];

void build(int i, int l, int r) {
  if (r < l) {
    return;
  }
  if (l == r) {
    seg[i] = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

void lazy_prop(int i, int l, int r) {
  if (lazy[i] != 0) {
    lazy[i] = 0;
    seg[i] = r - l + 1 - seg[i];
    if (l != r) {
      lazy[i * 2] = 1 - lazy[i * 2];
      lazy[i * 2 + 1] = 1 - lazy[i * 2 + 1];
    }
  }
}

void update(int i, int l, int r, int tar_l, int tar_r) {
  lazy_prop(i, l, r);
  if (r < l || r < tar_l || tar_r < l) {
    return;
  }
  if (tar_l <= l && r <= tar_r) {
    lazy[i] = 1 - lazy[i];
    lazy_prop(i, l, r);
    return;
  }
  int m = (l + r) >> 1;
  update(i * 2, l, m, tar_l, tar_r);
  update(i * 2 + 1, m + 1, r, tar_l, tar_r);
  seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

int get_on(int i, int l, int r, int tar_l, int tar_r) {
  lazy_prop(i, l, r);
  if (r < l || r < tar_l || tar_r < l) {
    return 0;
  }
  if (tar_l <= l && r <= tar_r) {
    return seg[i];
  }
  int m = (l + r) >> 1;
  return get_on(i * 2, l, m, tar_l, tar_r) + get_on(i * 2 + 1, m + 1, r, tar_l, tar_r);
}

int dfs(int u, int l) {
  a[++cnt] = p[u];
  in[u] = cnt;
  for (int v : adj[u]) {
    if (v != l) {
      dfs(v, u);
    }
  }
  a[++cnt] = p[u];
  out[u] = cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    adj[u].push_back(i);
    adj[i].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  dfs(1, 1);

  build(1, 1, 2 * n);

  cin >> q;
  while (q--) {
    string cmd;
    int x;
    cin >> cmd >> x;
    if (cmd[0] == 'g') {
      cout << get_on(1, 1, 2 * n, in[x], out[x]) / 2 << "\n";

    } else {
      update(1, 1, 2 * n, in[x], out[x]);
    }
  }
}