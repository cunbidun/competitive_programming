#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e6 + 4;
const int INF = 1e9;

int n, m, num;
int a[4][N], f[N][9], ans = INF;

int check(int j, int k) {
  for (int i = 0; i <= n - 2; i++) {
    int cnt = 0;
    if ((j >> i) & 1) {
      cnt++;
    }
    if ((j >> (i + 1)) & 1) {
      cnt++;
    }
    if ((k >> i) & 1) {
      cnt++;
    }
    if ((k >> (i + 1)) & 1) {
      cnt++;
    }
    if (cnt % 2 == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  if (n >= 4 && m >= 4) {
    cout << -1 << "\n";
    return 0;
  }
  if (n == 1 || m == 1) {
    cout << 0 << "\n";
    return 0;
  }
  if (n < m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        a[j][i] = c - '0';
      }
    }
  }
  if (n > m) {
    swap(m, n);
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j <= m; j++) {
      f[j][i] = INF;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0;
    for (int l = 0; l < n; l++) {
      if (((i >> l) & 1) != a[l + 1][1]) {
        cnt++;
      }
    }
    f[1][i] = cnt;
  }
  for (int i = 2; i <= m; i++) {
    for (int j = 0; j < (1 << n); j++) {
      int cnt = 0;
      for (int l = 0; l < n; l++) {
        if (((j >> l) & 1) != a[l + 1][i]) {
          cnt++;
        }
      }
      for (int k = 0; k < (1 << n); k++) {
        if (check(j, k)) {
          f[i][j] = min(f[i][j], f[i - 1][k] + cnt);
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < (1 << n); i++) {
    ans = min(ans, f[m][i]);
  }
  cout << ans << "\n";
}