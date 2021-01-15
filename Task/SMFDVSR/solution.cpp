#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  ll ans = 1;
  cin >> n;
  for (ll i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    ll res = 1;
    ll cur = 1;
    for (int j = 1; j <= cnt; j++) {
      res += cur;
    }
    ans *= res;
  }
  if (n > 1) {
    ans *= (n + 1);
  }
  cout << ans << "\n";
}
