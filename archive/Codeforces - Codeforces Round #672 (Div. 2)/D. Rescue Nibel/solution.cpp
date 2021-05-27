#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;

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
} Op(998244353);

int f[N];
ii a[N];

int c(int n, int k) {
  if (n < k) {
    return 0;
  }
  return Op.div(f[n], Op.mul(f[k], f[n - k]));
}

priority_queue<int, vector<int>, greater<int>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = Op.mul(f[i - 1], i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + 1 + n);
  int p = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    while (!q.empty() && a[i].first > q.top()) {
      q.pop();
    }
    ans = Op.add(ans, c(sz(q), k - 1));
    q.push(a[i].second);
  }
  cout << ans << "\n";
}