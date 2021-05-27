#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  ll n, ans = 1;
  cin >> n;
  ll f[70], cur = 1;
  f[0] = 1;
  for (int i = 1; i <= 50; i++) {
    f[i] = f[i - 1] + f[i - 1] + (1LL << (i * 2));
    cur += f[i];
    // cout << f[i] << " ";
    if (cur <= n) {
      ans++;
    } else {
      break;
    }
  }
  // cout << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}