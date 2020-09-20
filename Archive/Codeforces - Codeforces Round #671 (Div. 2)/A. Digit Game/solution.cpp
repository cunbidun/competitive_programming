#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  if (n % 2 == 1) {
    for (int i = 0; i < n; i += 2) {
      if ((s[i] - '0') % 2 == 1) {
        cout << "1\n";
        return;
      }
    }
    cout << "2\n";
  } else {
    for (int i = 1; i < n; i += 2) {
      if ((s[i] - '0') % 2 == 0) {
        cout << "2\n";
        return;
      }
    }
    cout << "1\n";
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