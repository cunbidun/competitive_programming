#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 << " " << n / 2 << "\n";
    return 0;
  }
  int a, b, cur = 1e9 + 7;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (max(i, n - i) < cur) {
        a = i,
        b = n - i;
        cur = max(i, n - i);
      }
			int pi = n/i;
			if (max(pi, n - pi) < cur) {
        a = pi,
        b = n - pi;
        cur = max(pi, n - pi);
      }
    }
  }
  cout << a << " " << b << "\n";
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