#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int solve() {
  string s;
  cin >> s;
  s = "*" + s;
  int p = 1;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  int ans = INF;
  rf(i, 1, sz(s) - 1) {
    if (s[i] == '1') cnt1++;
    if (s[i] == '2') cnt2++;
    if (s[i] == '3') cnt3++;

    while (p <= i) {
      int cur = p;
      if (cnt1 > 1 && s[p] == '1') {
        p++;
        cnt1--;
      }

      if (cnt2 > 1 && s[p] == '2') {
        p++;
        cnt2--;
      }

      if (cnt3 > 1 && s[p] == '3') {
        p++;
        cnt3--;
      }
      if (cur == p) break;
    }
    // cout << cnt1 << "\n";
    // cout << cnt2 << "\n";
    // cout << cnt3 << "\n";
    if (cnt1 > 0 && cnt2 > 0 && cnt3 > 0) ans = min(ans, i - p + 1);
  }
  if (ans == INF) {
    cout << 0 << '\n';
    return 0;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}