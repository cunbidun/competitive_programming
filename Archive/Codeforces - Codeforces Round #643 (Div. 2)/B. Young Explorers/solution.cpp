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

const int N = 2e5 + 1;
const int INF = 2e9;

int n, a[N];
int solve() {
  cin >> n;
  rf(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans = 0;
  rf(i, 1, n) {
    int cnt = 0;
    int j;
    for (j = i; j <= n; j++) {
      cnt++;
      if (cnt == a[j]) {
        break;
      }
    }
		if(j > n) break;
    i = j;
    ans++;
  }
  cout << ans << '\n';
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