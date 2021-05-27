#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  ll ans = 0, a, b;
  cin >> a >> b;
  for (int i = 33; i >= 0; i--) {
    if (((a >> i) & 1) != ((b >> i) & 1)) {
      ans += (1L << i);
    }
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