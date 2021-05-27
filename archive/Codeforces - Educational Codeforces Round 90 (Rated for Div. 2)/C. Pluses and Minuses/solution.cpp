#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  string s;
  cin >> s;
  int n = sz(s);
  s = '*' + s;
  int init = 0;
  int cur = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '-')
      cur--;
    else
      cur++;
    if (cur + init < 0) {
      ans += i;
      init++;
    }
  }
  cout << ans + n << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}