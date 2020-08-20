#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N];

int solve() {
  cin >> n;
  int ch = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1 && a[i] != a[i - 1]) {
      ch = 1;
    }
  }
  if (ch == 1) {
    cout << 1 << "\n";
  } else {
    cout << n << "\n";
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
