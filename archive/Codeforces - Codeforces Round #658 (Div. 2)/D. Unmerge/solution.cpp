#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[4003], f[4003];
int solve() {
  cin >> n;
  n *= 2;
  for (int i = 1; i <= n; i++) {
    f[i] = 0;
    cin >> a[i];
  }
  int p = n;
  vi l;
  while (p > 0) {
    int mx = a[1];
    int j = 1;
    for (int i = 2; i <= p; i++) {
      if (a[i] > mx) {
        mx = a[i];
        j = i;
      }
    }
    l.push_back(p - j + 1);
    p = j - 1;
  }
  sort(all(l));
  f[0] = 1;
  for (int j : l) {
    for (int i = n / 2; i >= 1; i--) {
      if (i < j) {
        break;
      }
      f[i] = max(f[i], f[i - j]);
    }
  }
  if (f[n / 2] == 1) {
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