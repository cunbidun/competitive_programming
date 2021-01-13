#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
int k[N], c[N], cnt[N];
int n, m;
int solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    cnt[k[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  int cur = 1;
  ll ans = 0;
  for (int i = m; i >= 1; i--) {
    while (cnt[i]--) {
      if (cur < i) {
        ans += c[cur];
        cur++;
      } else {
        ans += c[i];
      }
    }
  }
  cout << ans << "\n";
  return 0;
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
