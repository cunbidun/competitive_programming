#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  int n, m;
  set<int> s;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int ans = -1;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (s.find(x) != s.end()) {
      ans = x;
    }
  }
  if (ans != -1) {
    cout << "YES\n";
    cout << 1 << " " << ans << "\n";
  } else {
    cout << "NO\n";
  }
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