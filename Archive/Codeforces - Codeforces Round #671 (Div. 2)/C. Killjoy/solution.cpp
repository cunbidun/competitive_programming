#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, x, a[1001];
void solve() {
  cin >> n >> x;
  int s = 0;
  int ch = 0;
  int eq = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
    if (a[i] != x) {
      ch = 1;
    }
    if(a[i] == x) {
      eq = 1;
    }
  }
  if (!ch) {
    cout << 0 << "\n";
    return;
  }
  if(eq) {
    cout << 1 << "\n";
    return;
  }
  if (s == n * x) {
    cout << 1 << "\n";
  } else {
    cout << 2 << "\n";
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