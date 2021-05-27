#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct e {
  int cap, cur;
};

const int N = 1e2 + 5;

e a[N];

double f[2][N][N * N]; 
// f[i][j][k] = maximum value when consider ith element, with j elements already choosen, and with k extra unit
// extra unit is the amount of water in other cup that could add to current cup.

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  int S = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].cap >> a[i].cur;
    S += a[i].cur;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = S; k >= 0; k--) {
        int nk = k - a[i].cur;
        int add = min(nk, 2 * (a[i].cap - a[i].cur));
        f[1][j][nk - add] = max(f[1][j][nk - add], max(f[0][j][k], f[0][j - 1][k] + 2 * a[i].cur + add));
      }
    }
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= S; k++) {
        f[0][j][k] = f[1][j][k];
      }
    }
  }

  for (int j = 1; j <= n; j++) {
    double ans = 0.0;
    for (int k = 0; k <= S; k++) {
      ans = max(ans, f[0][j][k]);
    }
    cout << ans / 2.0 << " ";
  }
  cout << "\n";
}
