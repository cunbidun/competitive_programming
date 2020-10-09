#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[10005];
void solve() {
  cin >> n;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % n != 0) {
    cout << -1 << "\n";
    return;
  }
  vector<pair<ii, int>> ans;
  for (int i = 2; i <= n; i++) {
    if (a[i] % i == 0) {
      ans.push_back({{i, 1}, a[i] / i});
      a[1] += a[i];
      a[i] = 0;
    } else {
      int greater = i - a[i] % i;
      ans.push_back({{1, i}, greater});
      a[1] -= greater;
      a[i] += greater;
      ans.push_back({{i, 1}, a[i] / i});
      a[1] += a[i];
      a[i] = 0;
    }
  }
  for (int i = 2; i <= n; i++) {
    ans.push_back({{1, i}, s / n});
    a[1] -= s / n;
    a[i] = s / n;
  }
  cout << sz(ans) << "\n";
  for (pair<ii, int> T : ans) {
    cout << T.first.first << " " << T.first.second << " " << T.second << "\n";
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