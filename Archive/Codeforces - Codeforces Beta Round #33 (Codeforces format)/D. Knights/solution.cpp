#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e3 + 5;

int n, m, k;
ii a[N];
pair<int, ii> c[N];

int inside(int i, int j) {
  ll dis = 1LL * abs(c[j].second.first - a[i].first) * abs(c[j].second.first - a[i].first);
  dis += 1LL * abs(c[j].second.second - a[i].second) * abs(c[j].second.second - a[i].second);
  return 1LL * c[j].first * c[j].first >= dis;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= m; i++) {
    int r, x, y;
    cin >> r >> x >> y;
    c[i] = {r, {x, y}};
  }
  while (k--) {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      if ((inside(y, i) && inside(x, i)) || (!inside(y, i) && !inside(x, i))) {
        continue;
      }
      ans++;
    }
    cout << ans << "\n";
  }
}