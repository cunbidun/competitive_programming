#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m, q, sum[44][44], cnt[44][44][44][44], vis[44][44][44][44];

int cal(int i, int j, int k, int l) {
  if (i > k || j > l) {
    return 0;
  }
  if (vis[i][j][k][l]) {
    return cnt[i][j][k][l];
  }
  vis[i][j][k][l] = 1;

  int v = 0;
  v = (sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1] == 0);
  v += cal(i + 1, j, k, l) + cal(i, j + 1, k, l) + cal(i, j, k - 1, l) + cal(i, j, k, l - 1);

  v -= cal(i, j + 1, k - 1, l);
  v -= cal(i, j, k - 1, l - 1);
  v -= cal(i + 1, j + 1, k, l);
  v -= cal(i + 1, j, k, l - 1);

  v -= cal(i + 1, j, k - 1, l);
  v -= cal(i, j + 1, k, l - 1);

  v += cal(i, j + 1, k - 1, l - 1);
  v += cal(i + 1, j, k - 1, l - 1);
  v += cal(i + 1, j + 1, k - 1, l);
  v += cal(i + 1, j + 1, k, l - 1);

  v -= cal(i + 1, j + 1, k - 1, l - 1);

  return cnt[i][j][k][l] = v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      vis[i][j][i][j] == 1;
      if (i == 0 || j == 0) {
        sum[i][j] = 0;
      } else {
        char x;
        cin >> x;
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x - '0';
      }
    }
  }
  cal(1, 1, n, m);
  while (q--) {
    int i, j, k, l;
    cin >> i >> j >> k >> l;
    cout << cnt[i][j][k][l] << "\n";
  }
}
