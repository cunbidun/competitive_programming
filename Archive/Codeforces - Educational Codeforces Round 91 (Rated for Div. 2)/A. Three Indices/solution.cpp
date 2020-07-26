#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[1001];
int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n - 1; i++) {
    int pj = -1, pk = -1;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        pj = j;
        break;
      }
    }
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[i]) {
        pk = j;
        break;
      }
    }
    if (pj != -1 && pk != -1) {
      cout << "YES\n";
      cout << pj << " " << i << " " << pk << "\n";
      return 0;
    }
  }
  cout << "NO\n";
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