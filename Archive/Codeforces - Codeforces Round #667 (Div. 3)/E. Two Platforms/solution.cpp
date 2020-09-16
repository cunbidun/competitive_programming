#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, k, x[N], f[N];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    f[i] = 0;
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
  }
  sort(x + 1, x + 1 + n);
  int mx = 0;
  int p = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + 1;
    while (x[i] - x[p] > k) {
      mx = max(mx, f[p]);
      p++;
      f[i]--;
    }
    ans = max(ans, mx + f[i]);
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