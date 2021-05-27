#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e3 + 5;
const int INF = 2e9 + 7;

int n, m, mx[N * N];

ii a[N], l[N];
vector<ii> p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= m; i++) {
    cin >> l[i].first >> l[i].second;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i].first <= l[j].first && a[i].second <= l[j].second) {
        p.push_back({l[j].first - a[i].first + 1, l[j].second - a[i].second + 1});
      }
    }
  }
  sort(all(p));
  if (sz(p) == 0) {
    cout << 0 << "\n";
    return 0;
  }
  mx[sz(p)] = 0;
  for (int i = sz(p) - 1; i >= 0; i--) {
    mx[i] = max(mx[i + 1], p[i].second);
  }
  int ans = min(mx[0], p[sz(p) - 1].first);
  for (int i = 0; i < sz(p) - 1; i++) {
    ans = min(ans, p[i].first + mx[i + 1]);
  }
  cout << ans << "\n";
}
