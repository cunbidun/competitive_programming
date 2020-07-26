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

int n, a[N], cnt[N];
ll ans = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  rf(i, 1, n) cin >> a[i];
  if (n == 1) return cout << a[1] << "\n", 0;
  rf(j, 2, sqrt(N)) {
    int mn1 = INF, mn2 = INF;
    rf(i, 1, n) {
      int cnt = 0;
      while (a[i] % j == 0) {
        cnt++;
        a[i] /= j;
      }
      if (cnt < mn1) {
        mn2 = mn1;
        mn1 = cnt;
      } else {
        mn2 = min(mn2, cnt);
      }
    }
    rf(k, 1, mn2) ans *= 1LL * j;
  }
  rf(i, 1, n) {
    if (a[i] != 1) {
      // cout << a[i] << " ";
      cnt[a[i]]++;
    }
  }
  rf(i, 1, N - 1) if (cnt[i] >=n-1 ) { ans *= 1LL * i; }
  cout << ans << "\n";
}