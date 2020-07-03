#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  ll a, b, c;
	cin >> a >> b >> c;
  if (a >= c) {
    cout << -1 << " " << b << "\n";
    return 0;
  }
  if (a * b <= c) {
    cout << 1 << " " << -1 << '\n';
    return 0;
  } else {
    cout << 1 << " " << b << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}