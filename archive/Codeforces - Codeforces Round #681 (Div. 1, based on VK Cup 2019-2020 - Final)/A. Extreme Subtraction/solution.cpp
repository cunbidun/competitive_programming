#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e4 + 5;
int n, a[N], mn[N];

void solve() {
  cin >> n;
  mn[0] = 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn[i] = min(mn[i - 1], a[i]);
  }
  int sub = 0;
  for (int i = n - 1; i >= 1; i--) {
    sub += max(a[i] - a[i + 1], 0);
    if (sub > mn[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
