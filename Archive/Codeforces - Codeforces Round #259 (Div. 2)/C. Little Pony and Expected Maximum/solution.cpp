#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

double bin_pow(double a, int p) {
  if (p == 0) {
    return 1.0;
  }
  if (p == 1) {
    return a;
  }
  double t = bin_pow(a, p / 2);
  if (p % 2 == 0) {
    return t * t;
  } else {
    return t * t * a;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(10) << "\n";
  int n, m;
  cin >> m >> n;
  double ans = m;
  for (int i = m - 1; i >= 1; i--) {
    ans -= bin_pow(1.0 * (i) / m, n);
  }
  cout << ans << "\n";
}