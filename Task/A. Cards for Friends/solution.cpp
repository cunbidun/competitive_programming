#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int w, h, n;
  cin >> w >> h >> n;
  int c1 = 1, c2 = 1;
  while (w % 2 == 0) {
    w /= 2;
    c1 *= 2;
  }
  while (h % 2 == 0) {
    h /= 2;
    c2 *= 2;
  }
  if (c1 * c2 >= n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
