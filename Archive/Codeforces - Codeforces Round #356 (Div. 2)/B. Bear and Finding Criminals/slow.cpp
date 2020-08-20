#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

// Code below this line will be copied.
int a[105];
int main() {
  int n, cp, m = 0, d, nt = 0;
  cin >> n;
  cin >> cp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (a[cp] == 1) {
    nt = nt + 1;
  }
  for (int i = 1; i <= cp - 1; i++) {
    if (a[cp - i] == 1 && a[cp + i] == 1) {
      nt = nt + 2;
    }
    if (a[cp + i] == 1 && cp - i <= 0) {
      nt = nt + 1;
    }
    if (a[cp - i] == 1 && cp + i > n) {
      nt = nt + 1;
    }
  }
  d = 2 * cp;
  if (cp + cp - 1 < n) {
    for (int i = d; i <= n; i++) {
      if (a[i] == 1) {
        nt = nt + 1;
      }
    }
  }
  cout << nt;
}
