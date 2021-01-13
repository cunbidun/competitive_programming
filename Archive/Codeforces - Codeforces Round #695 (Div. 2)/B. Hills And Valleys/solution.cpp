#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
int n, a[N], l[N], r[N];

int check(int i) {
  return (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]);
}

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n <= 4) {
    cout << 0 << "\n";
    return 0;
  }
  l[1] = 0, r[n] = 0;
  for (int i = 2; i < n; i++) {
    l[i] = l[i - 1] + check(i);
  }

  for (int i = n - 1; i >= 2; i--) {
    r[i] = r[i + 1] + check(i);
  }
  int ans = min(r[4], l[n - 3]);
  for (int i = 3; i <= n - 2; i++) {
    ans = min(ans, l[n - 1] - check(i) - check(i - 1) - check(i + 1) + ((a[i + 1] > a[i - 1] && a[i + 1] > a[i + 2]) || (a[i + 1] < a[i - 1] && a[i + 1] < a[i + 2])));
    ans = min(ans, l[n - 1] - check(i) - check(i - 1) - check(i + 1) + ((a[i - 1] > a[i + 1] && a[i - 1] > a[i - 2]) || (a[i - 1] < a[i + 1] && a[i - 1] < a[i - 2])));
  }
  cout << ans << '\n';
  return 0;
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
