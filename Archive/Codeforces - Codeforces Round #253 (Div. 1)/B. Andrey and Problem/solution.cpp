#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e2 + 5;
int n;
double a[N], ans = 0.0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1.0) {
      cout << 1.0 << "\n";
      return 0;
    }
  }
  double S = 0.0, P = 1.0;
  sort(a, a + n + 1);
  for (int i = n; i >= 1; i--) {
    S += a[i] / (1.0 - a[i]);
    P *= (1 - a[i]);
    ans = max(ans, S * P);
  }
  cout << ans << "\n";
}
