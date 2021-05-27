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
  if (n <= 30) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (n == 36) {
    cout << "5 6 10 15\n";
  } else if (n == 44) { 
    cout << "6 7 10 21\n";
  } else if (n == 40) {
    cout << "9 15 6 10\n";
  } else {
    cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << "\n";
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