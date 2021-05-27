#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  ll n;
  cin >> n;
  while (n > 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
