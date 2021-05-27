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
  int n8 = (n + 3) / 4;
  for (int i = 1; i <= n - n8; i++) {
    cout << 9;
  }
  for (int i = 1; i <= n8; i++) {
    cout << 8;
  }
  cout << "\n";
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