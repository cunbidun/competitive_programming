#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  ll a, b, n, m;
  cin >> a >> b >> n >> m;
  if (a + b < n + m) {
    cout << "No\n";
    return 0;
  }
  if (min(a, b) < m) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
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