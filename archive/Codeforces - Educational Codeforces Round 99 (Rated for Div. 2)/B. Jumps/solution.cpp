#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int x;
  cin >> x;
  int cur = 0;
  int d = 0;
  while (d < x) {
    cur++;
    d += cur;
  }
  if (d == x + 1) {
    cout << cur + 1 << "\n";
  } else {
    cout << cur << "\n";
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