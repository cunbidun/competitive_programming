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

const double pi = 3.14159265;

int solve() {
  int n;
  cin >> n;
  n *= 2;
  double de = (n - 2) * 180 / (1.0 * n);
  double r = 2 / (2 * sin(180.0 / n / 180 * pi));
  // cout << sin(45.0 / 180 * pi) << "\n";

  cout << sqrt(r * r - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(10);
  int t;
  cin >> t;
  while (t--) solve();
}