#include <bits/stdc++.h>
 
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
const int N = 3e5 + 5;
int n, a[N];
void solve() {
  unordered_map<int, int> m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int res = 1;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        int cnt = 0;
        while (x % j == 0) {
          x /= j;
          cnt++;
        }
        if (cnt % 2 == 1) {
          res *= j;
        }
      }
    }
    if (x > 1) {
      res *= x;
    }
    a[i] = res;
    // cout << a[i] << " ";
    m[a[i]]++;
  }
  // cout << "\n";
  int no_change = 0;
  int first = 0;
  int cnt = 0;
  int cnt1 = m[1];
  for (int i = 1; i <= n; i++) {
    if (a[i] != 1) {
      int tmp = m[a[i]];
      first = max(first, tmp);
      if (tmp % 2 == 1) {
        no_change = max(no_change, tmp);
      } else {
        cnt++;
      }
    }
  }
  int w;
  cin >> w;
  while (w--) {
    ll q;
    cin >> q;
    if (q == 0) {
      cout << max(cnt1, first) << "\n";
    } else {
      cout << max(no_change, cnt + cnt1) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
