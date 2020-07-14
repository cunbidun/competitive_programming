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

int bin_pow(int a, int x) {
  if (x == 0) return 1;
  if (x == 1) return a;
  int t = bin_pow(a, x / 2);
  if (x % 2 == 0)
    return t * t;
  else
    return t * t * x;
}

int solve() {
  int n;
  cin >> n;
  int p = 0;

  vi ans;
  while (n) {
    if (n % 10 != 0) {
      ans.pb(n % 10 * bin_pow(10, p));
    }
    p++;
    n /= 10;
  }

  cout << sz(ans) << '\n';
  for (int i : ans) cout << i << " ";
  cout << '\n';
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