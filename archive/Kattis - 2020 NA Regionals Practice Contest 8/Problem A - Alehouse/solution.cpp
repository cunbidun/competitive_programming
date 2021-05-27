#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<ii> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    y += k;
    v.push_back({x, -1});
    v.push_back({y, +1});
  }
  sort(all(v));
  int ans = 0;
  int cur = 0;
  for (ii i : v) {
    cur -= i.second;
    ans = max(ans, cur);
  }
  cout << ans << "\n";
}
