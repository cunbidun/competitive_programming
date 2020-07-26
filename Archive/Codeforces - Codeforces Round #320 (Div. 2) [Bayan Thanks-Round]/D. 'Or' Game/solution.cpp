#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;
int n;
int cnt[40];
ll a[N], k, x, mul = 1, ans = 0;

void solve(ll x) {
  int tmp[40];
  ll res = 0;
  for (int i = 0; i < 31; i++) {
    tmp[i] = cnt[i];
		if (((x >> i) & 1) == 1) {
      tmp[i]--;
    }		
    if (tmp[i] > 0) {
      res += 1LL << i;
    }
  }
  ans = max(ans, res | (x * mul));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> x;
  while (k--) {
    mul *= x;
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans |= a[i];
    for (int j = 0; j < 31; j++) {
      if (((a[i] >> j) & 1) == 1) {
        cnt[j]++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    solve(a[i]);
  }
  cout << ans << "\n";
}