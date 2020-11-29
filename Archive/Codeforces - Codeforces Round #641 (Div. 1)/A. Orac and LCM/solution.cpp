#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int n, a[N];
int l[N], r[N], mx[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = __gcd(l[i - 1], a[i]);
  }
  for (int i = n; i >= 1; i--) {
    r[i] = __gcd(r[i + 1], a[i]);
  }
  for (int i = 1; i <= n; i++) {
    int cur = __gcd(l[i - 1], r[i + 1]);
    for (int j = 2; j * j <= cur; j++) {
      int cnt = 0;
      while (cur % j == 0) {
        cnt++;
        cur /= j;
      }
      mx[j] = max(mx[j], cnt);
    }
    if (cur > 1) {
      mx[cur] = max(mx[cur], 1);
    }
  }
  ll ans = 1LL;
  for (int i = 1; i < N; i++) {
    while (mx[i]--) {
      ans *= i;
    }
  }
  cout << ans << "\n";
}
