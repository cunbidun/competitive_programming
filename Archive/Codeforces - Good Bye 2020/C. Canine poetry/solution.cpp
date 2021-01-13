#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < sz(s); i++) {
    if (s[i] == s[i - 1]) {
      s[i] = '*';
      ans++;
    } else if (i > 1 && s[i] == s[i - 2]) {
      s[i] = '*';
      ans++;
    }
  }
  cout << ans << "\n";
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
