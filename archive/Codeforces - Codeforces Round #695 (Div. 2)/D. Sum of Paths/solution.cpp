#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct modInt {
  int MOD;

  modInt(int MOD) {
    this->MOD = MOD;
  }

  int add(int x, int y) {
    return ((x + y) >= MOD ? x + y - MOD : x + y);
  }

  int sub(int x, int y) {
    return ((x - y) < 0 ? x - y + MOD : x - y);
  }

  int mul(int x, int y) {
    return (int)((1LL * x * y) % MOD);
  }

  int pow(int x, ll p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }

  int inv(int x) {
    return pow(x, MOD - 2);
  }

  int div(int x, int y) {
    return mul(x, inv(y));
  }
} op(1e9 + 7);

const int N = 5e3 + 5;
int n, k, q, c[N], arr[N], a[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) {
    a[k + 1][i] = 1;
    cin >> arr[i];
  }
  for (int i = k; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = op.add(a[i + 1][j - 1], a[i + 1][j + 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    c[i] = 0;
    for (int j = 1; j <= k + 1; j++) {
      c[i] = op.add(c[i], op.mul(a[j][i], a[k + 2 - j][i]));
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = op.add(ans, op.mul(c[i], arr[i]));
  }
  while (q--) {
    int p, x;
    cin >> p >> x;
    ans = op.sub(ans, op.mul(arr[p], c[p]));
    arr[p] = x;
    ans = op.add(ans, op.mul(arr[p], c[p]));
    cout << ans << "\n";
  }
}
