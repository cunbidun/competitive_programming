#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 55;

int n, m, a[N];
double f[N][N][N], p[N];

ll c[N][N];
void pre_cal_C(int mx) {
  for (int i = 0; i <= mx; i++) {
    c[i][0] = 1;
  }
  c[1][1] = 1;
  for (int i = 2; i <= mx; i++) {
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  pre_cal_C(50);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  p[0] = 1.0;
  for (int i = 1; i <= 50; i++) {
    p[i] = p[i - 1] / m;
  }

  f[0][0][0] = 1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i <= n; i++) {
      for (int k = 0; k <= n; k++) {
        for (int l = 0; l <= n - i; l++) {
          int mx = max(k, (l + a[j + 1] - 1) / a[j + 1]);
          f[i + l][j + 1][mx] += p[l] * c[n - i][l] * f[i][j][k];
        }
      }
    }
  }

  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[n][m][i] * i;
  }
  cout << ans << "\n";
}