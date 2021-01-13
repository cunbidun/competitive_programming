#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;

const int N = 5e5 + 5;
int n, cnt[65], ba[N], bo[N];
ll a[N];

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
} op(1e9 + 7);

void solve() {
  cin >> n;
  for (int i = 0; i <= 60; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    a[i] = x;
    for (int i = 0; i <= 60; i++) {
      if (((x >> i) & 1) == 1) {
        cnt[i]++;
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    int cur = 0;
    for (int i = 0; i <= 60; i++) {
      if (((a[j] >> i) & 1) == 1) {
        cur = op.add(cur, op.mul((1LL << i) % MOD, cnt[i]));
      }
    }
    ba[j] = cur;
  }

  for (int j = 1; j <= n; j++) {
    int cur = 0;
    for (int i = 0; i <= 60; i++) {
      if (((a[j] >> i) & 1) == 1) {
        cur = op.add(cur, op.mul((1LL << i) % MOD, n));
      } else {
        if (cnt[i] > 0) {
          cur = op.add(cur, op.mul(cnt[i], (1LL << i) % MOD));
        }
      }
    }
    bo[j] = cur;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = op.add(ans, op.mul(ba[i], bo[i]));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
