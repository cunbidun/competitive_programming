#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int G[70000];

int process(int num) {
  int a[5][5], s[5][5];
  for (int i = 0; i < 16; i++) {
    a[i / 4 + 1][i % 4 + 1] = ((num >> i) & 1);
  }
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      s[i][j] = 0;
    }
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
    }
  }
  int mex = 0;
  set<int> cur;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = i; k <= 4; k++) {
        for (int l = j; l <= 4; l++) {
          if (s[k][l] + s[i - 1][j - 1] - s[i - 1][l] - s[k][j - 1] == (k - i + 1) * (l - j + 1)) {
            int nn = 0;
            int cnt = -1;
            for (int ii = 1; ii <= 4; ii++) {
              for (int jj = 1; jj <= 4; jj++) {
                cnt++;
                if ((ii >= i && ii <= k && jj >= j && jj <= l) || a[ii][jj] == 0) {
                  continue;
                }
                nn += 1 << cnt;
              }
            }
            cur.insert(G[nn]);
            while (cur.find(mex) != cur.end()) {
              mex++;
            }
          }
        }
      }
    }
  }
  G[num] = mex;
}

const int N = 1e5 + 5;

int seg[4 * N];
int a[N];

void build(int i, int l, int r) {
  if (l > r) {
    return;
  }
  if (l == r) {
    seg[i] = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  seg[i] = (seg[i * 2] ^ seg[i * 2 + 1]);
}

void update(int i, int l, int r, int p, int v) {
  if (l > r || p > r || l > p) {
    return;
  }
  if (l == r) {
    if (l == p) {
      seg[i] = v;
    }
    return;
  }
  int m = (l + r) >> 1;
  update(i * 2, l, m, p, v);
  update(i * 2 + 1, m + 1, r, p, v);
  seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
}

int get_xor(int i, int l, int r, int tar_l, int tar_r) {
  if (l > r || tar_l > r || l > tar_r) {
    return 0;
  }
  if (tar_l <= l && r <= tar_r) {
    return seg[i];
  }
  int m = (l + r) >> 1;
  return get_xor(i * 2, l, m, tar_l, tar_r) ^ get_xor(i * 2 + 1, m + 1, r, tar_l, tar_r);
}

int solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int num = 0;
    int cnt = 0;
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= 4; k++) {
        char x;
        cin >> x;
        if (x == '1') {
          num += 1 << cnt;
        }
        cnt++;
      }
    }
    a[i] = G[num];
  }
  build(1, 1, n);
  while (m--) {
    int c;
    cin >> c;
    if (c == 1) {
      int l, r;
      cin >> l >> r;
      if (get_xor(1, 1, n, l, r) > 0) {
        cout << "Pishty\n";
      } else {
        cout << "Lotsy\n";
      }
    } else {
      int p;
      cin >> p;
      int num = 0;
      int cnt = 0;
      for (int j = 1; j <= 4; j++) {
        for (int k = 1; k <= 4; k++) {
          char x;
          cin >> x;
          if (x == '1') {
            num += 1 << cnt;
          }
          cnt++;
        }
      }
      update(1, 1, n, p, G[num]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  G[0] = 0;
  for (int i = 1; i <= (1 << 16) - 1; i++) {
    process(i);
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}