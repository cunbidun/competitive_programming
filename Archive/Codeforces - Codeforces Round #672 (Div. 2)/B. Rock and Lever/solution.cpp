#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, cnt[64];
void solve() {
  cin >> n;
  for (int i = 0; i <= 40; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    for (int i = 35; i >= 0; i--) {
      if (((x >> i) & 1) == 1) {
        cnt[i]++;
        break;
      } 
    }
  }
  ll ans = 0;
  for (int i = 0; i <= 40; i++) {
    ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
  }
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