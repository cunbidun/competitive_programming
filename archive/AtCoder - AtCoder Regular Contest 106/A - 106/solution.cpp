#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  for (int i = 1; i < 66; i++) {
    for (int j = 1; j < 66; j++) {
      ll c5 = 5, c3 = 3;
      int ch = 0;
      for (int k = 2; k <= i; k++) {
        if (c3 > n / 3) {
          ch = 1;
          break;
        }
        c3 *= 3;
      }
      for (int k = 2; k <= j; k++) {
        if (c5 > n / 5) {
          ch = 1;
          break;
        }
        c5 *= 5;
      }
      if (c3 + c5 == n && ch == 0) {
        cout << i << " " << j << "\n";
        return 0;
      }
    }
  }
  cout << -1 << "\n";
}