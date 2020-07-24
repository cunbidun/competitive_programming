#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 50005;
const int INF = 1e9;
int n, q, a[N];

struct node {
  int v, s, l, r;
} seg[4 * N];

void build(int i, int l, int r) {
  if (l == r) {
    seg[i].v = a[l];
    seg[i].l = a[l];
    seg[i].r = a[l];
    seg[i].s = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  seg[i].v = max(seg[i * 2].v, seg[i * 2 + 1].v);
  seg[i].v = max(seg[i].v, seg[i * 2].r + seg[i * 2 + 1].l);
  seg[i].s = seg[i * 2].s + seg[i * 2 + 1].s;
  seg[i].l = max(seg[i * 2].l, seg[i * 2].s + seg[i * 2 + 1].l);
  seg[i].r = max(seg[i * 2 + 1].r, seg[i * 2 + 1].s + seg[i * 2].r);
}

node get_max(int i, int l, int r, int tar_l, int tar_r) {
  if (tar_l > r || l > tar_r) {
    return {-INF, 0, -INF, -INF};
  }
  if (tar_l <= l && r <= tar_r) {
    return seg[i];
  }
  int m = (l + r) >> 1;
  node left = get_max(i * 2, l, m, tar_l, tar_r);
  node right = get_max(i * 2 + 1, m + 1, r, tar_l, tar_r);
  int iv = max(left.v, right.v);
  iv = max(iv, left.r + right.l);
  int is = left.s + right.s;
  int il = max(left.l, left.s + right.l);
  int ir = max(right.r, right.s + left.r);
  return {iv, is, il, ir};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i < 4 * n; i++) {
    seg[i] = {-INF, 0, -INF, -INF};
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << get_max(1, 1, n, l, r).v << "\n";
  }
}