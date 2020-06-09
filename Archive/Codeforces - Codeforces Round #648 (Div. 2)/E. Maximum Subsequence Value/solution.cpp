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

int n;
ll a[501];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ll ans = 0;
  rf(i, 1, n) cin >> a[i];
  rf(i, 1, n) rf(j, 1, n) rf(k, 1, n) ans = max(ans, a[i] | a[j] | a[k]);
  cout << ans << "\n";
}