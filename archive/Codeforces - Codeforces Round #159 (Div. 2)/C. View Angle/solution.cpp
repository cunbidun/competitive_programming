#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)
#define PI 3.14159265

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

vector<double> l;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(10);
  int n;
  cin >> n;
  rf(i, 1, n) {
    int x, y;
    cin >> x >> y;
    if (x == 0) {
      if (y > 0) l.pb(90.0);
      if (y < 0) l.pb(270.0);
    } else if (y == 0) {
      if (x > 0) l.pb(0.0);
      if (x < 0) l.pb(180.0);
    } else {
      double cur = (atan(1.0 * y / x) * 180 / PI);
      if (x > 0 && y > 0) l.pb(cur);
      if (x < 0 && y > 0) l.pb(cur + 180);
      if (x < 0 && y < 0) l.pb(cur + 180);
      if (x > 0 && y < 0) l.pb(cur + 360);
    }
  }
  // for (double d : l) cout << d << " ";
  sort(all(l));
  if (sz(l) < 2) return cout << 0 << '\n', 0;
  double ans = 2e9;
  rf(i, 1, sz(l) - 1) ans = min(ans, 360 - (l[i] - l[i - 1]));
  cout << min(ans, l[sz(l) - 1] - l[0]) << '\n';
}