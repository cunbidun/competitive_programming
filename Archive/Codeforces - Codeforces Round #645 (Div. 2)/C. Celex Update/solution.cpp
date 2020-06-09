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
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll a = x2 - x1, b = y2 - y1;
  if (a > b) swap(a, b);
  ll n = min(a, b);
  cout << n * (n - 1) / 2 + n * (n + 1) / 2 + (b - a) * (n) + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}