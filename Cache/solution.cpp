#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

struct modInt {
  int MOD;

  modInt(int MOD) { this->MOD = MOD; }

  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }

  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }

  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }

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

  int inv(int x) { return pow(x, MOD - 2); }

  int div(int x, int y) { return mul(x, inv(y)); }
} Op(1e9 + 7);

int n, a[N], num[N];
vi l[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int mx = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  sort(a + 1, a + n + 1);
  a[n + 1] = 99999999;
  int p = 0;
  for (int i = 1; i <= mx; i++) {
    while (a[p + 1] < i) {
      p++;
    }
    num[i] = n - p;
  }

  int ans = 1;
  for (int i = 2; i <= mx; i++) {
    vi l;
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        l.push_back(j);
        if (j != i / j) {
          l.push_back(i / j);
        }
      }
    }
    sort(all(l));
    int res = 1;
    int j = 0;
    for (int j = 1; j < sz(l) - 1; j++) {
      // cout << j + 1 << " " << num[l[i][j]] << "\n";
      res = Op.mul(res, Op.pow(j + 1, num[l[j]] - num[l[j + 1]]));
    }
    res = Op.mul(res, Op.sub(Op.pow(sz(l), num[i]), Op.pow(sz(l) - 1, num[i])));
    ans = Op.add(ans, res);
  }

  cout << ans << "\n";
}