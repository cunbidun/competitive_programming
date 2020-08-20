#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m, a[1001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  if (a[m] == 1) {
    ans++;
  }
  for (int i = 1; i <= n; i++) {
    if (m - i < 1) {
      ans += a[m + i];
    } else if (m + i > n) {
      if (m - i > 0) {
        ans += a[m - i];
      }
    } else if (a[m + i] == 1 && a[m - i] == 1) {
      ans += 2;
    }
  }
  cout << ans << "\n";
}
