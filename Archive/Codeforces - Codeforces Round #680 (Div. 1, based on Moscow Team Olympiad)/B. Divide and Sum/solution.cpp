#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
const int MOD = 998244353;

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
} op(MOD);

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int u = 1, l = 1;
  for (int i = 1; i <= 2 * n; i++) {
    u = op.mul(u, i);
    if (i <= n) {
      l = op.mul(l, i);
    }
    cin >> a[i];
  }
  sort(a + 1, a + 2 * n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i] % MOD;
    cur = op.sub(cur, a[i]);
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    a[i] = a[i] % MOD;
    cur = op.add(cur, a[i]);
  }
  int c = op.div(u, op.mul(l, l));
  cout << op.mul(c, cur) << "\n";
}
