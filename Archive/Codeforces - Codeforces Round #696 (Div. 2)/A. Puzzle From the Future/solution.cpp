#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int n;
  string ans = "";
  cin >> n;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    char x;
    cin >> x;
    int v = x - '0';
    v = x - '0';
    if (last == 2) {
      ans += to_string(1 - v);
      last = 1;
    } else if (last == 1) {
      ans += to_string(v);
      last = v + v;
    } else {
      ans += to_string(1);
      last = v + 1;
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
