#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

ll n, m, x, y, cnt;
char a[101][1001];
int solve() {
  ll ans = 0;
  cnt = 0;
  cin >> n >> m >> x >> y;
  rf(i, 1, n) rf(j, 1, m) {
    cin >> a[i][j];
    if (a[i][j] == '.') cnt++;
  }
  if (2 * x <= y) return cout << x * cnt << "\n", 0;
  rf(i, 1, n) {
    int cur = 0;
    rf(j, 1, m) {
      if (a[i][j] == '.')
        cur++;
      else {
        ans += cur / 2 * y + (cur % 2) * x;
        cur = 0;
      }
    }
    ans += cur / 2 * y + (cur % 2) * x;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}