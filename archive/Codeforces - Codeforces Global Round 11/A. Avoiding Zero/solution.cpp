#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[55];
void solve() {
  cin >> n;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a + 1, a + 1 + n);
  if (s < 0) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";

  } else if (s > 0) {
    cout << "YES\n";
    for (int i = n; i >= 1; i--) {
      cout << a[i] << " ";
    }
    cout << "\n";
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