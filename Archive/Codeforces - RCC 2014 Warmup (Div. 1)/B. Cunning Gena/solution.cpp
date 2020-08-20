#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 105;
const ll INF = 2e18 + 7;

int n, m, b;
ll dp[1 << 20], ans = INF;

struct f {
  int price, monitor, problems;
} a[N];

bool cmp(f A, f B) {
  return A.monitor < B.monitor;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> b;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> a[i].price >> a[i].monitor >> x;
    for (int j = 1; j <= x; j++) {
      int y;
      cin >> y;
      a[i].problems |= (1 << (y - 1));
    }
  }
  sort(a + 1, a + n + 1, cmp);
  for (int j = 0; j < (1 << m); j++) {
    dp[j] = INF;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      int jp = j | a[i].problems;
      dp[jp] = min(dp[jp], dp[j] + a[i].price);
      if (jp == (1 << m) - 1) {
        ans = min(ans, dp[jp] + 1ll * a[i].monitor * b);
      }
    }
  }
  if (ans == INF) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}