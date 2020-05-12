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

int n, k, cnt = 0;
int a[N];

int solve() {
  cin >> n >> k;
  cnt = 0;
  rf(i, 1, n) {
    cin >> a[i];
    if (a[i] > k)
      a[i] = 1;   
    else if (a[i] < k)
      a[i] = -1;
    else {
      a[i] = 1;
      cnt++;
    }
  }
  if (cnt == n) return cout << "yes\n", 0;
  if (cnt == 0) return cout << "no\n", 0;

  int ans = 0;
  rf(i, 1, n - 1) ans |= (a[i] == 1 && a[i] == a[i + 1]);
  rf(i, 1, n - 2) ans |= (a[i] == 1 && a[i] == a[i + 2]);

  if (ans)
    cout << "yes\n";
  else
    cout << "no\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
