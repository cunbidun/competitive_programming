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

int n, f[N], a[N];
int solve() {
  cin >> n;
  rf(i, 1, n) {
    f[i] = 1;
    cin >> a[i];
  }
  int ans = 1;

  rf(i, 2, n) {
    // if (a[i] > a[1]) f[i] = 2;
    rf(j, 1, sqrt(i)) if (i % j == 0) {
      if (a[i] > a[j]) f[i] = max(f[j] + 1, f[i]);
      if (a[i] > a[i / j]) f[i] = max(f[i / j] + 1, f[i]);
      ans = max(ans, f[i]);
    }
  }
  // rf(i, 1, n) cout << f[i] << " ";
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