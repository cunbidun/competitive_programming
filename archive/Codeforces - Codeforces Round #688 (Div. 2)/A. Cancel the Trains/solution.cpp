#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int n, m;
  cin >> n >> m;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (s.find(x) != s.end()) {
      ans++;
    }
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