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
  cin >> n;
  int ans = 0;
  for (ll i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    for (int i = 1;; i++) {
      if (cnt >= i) {
        ans++;
        cnt -= i;
      } else {
        break;
      }
    }
  }
  if (n > 1) {
    ans++;
  }
  cout << ans << "\n";
}