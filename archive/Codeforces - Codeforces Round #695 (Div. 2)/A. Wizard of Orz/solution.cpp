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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 9 << "\n";
    } else {
      cout << 98 ;
      n -= 2;
      int cur = 9;
      while (n--) {
        cout << cur;
        cur++;
        if (cur == 10) {
          cur -= 10;
        }
      }
      cout << "\n";
    }
  }
}
