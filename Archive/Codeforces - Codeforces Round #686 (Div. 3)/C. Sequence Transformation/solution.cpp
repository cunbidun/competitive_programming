#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N], cnt[N];
vi l[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      cnt[a[i]]++;
    }
  }
  int ans = N;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 0) {
      int cur = cnt[i] + 1;
      // cout << i << " " << cur << "\n";
      if (a[1] == i) {
        cur--;
      }
      if (a[n] == i) {
        cur--;
      }
      ans = min(ans, cur);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}