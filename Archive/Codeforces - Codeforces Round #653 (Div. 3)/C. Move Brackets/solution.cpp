#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int solve() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '(') {
      cnt++;
    } else {
      cnt--;
    }
    if (cnt < 0) {
      ans++;
      cnt++;
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
