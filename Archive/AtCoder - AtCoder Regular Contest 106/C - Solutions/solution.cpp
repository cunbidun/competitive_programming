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
  int n, m;
  cin >> n >> m;
  if (m == 0 && n == 1) {
    cout << 1 << " " << 10 << "\n";
    return 0;
  }
  if (m < 0 || m >= n - 1) {
    cout << -1 << "\n";
    return 0;
  }
  int cnt = 0;
  for (int i = 1;; i += 2) {
    cnt++;
    cout << i * 2 << " " << i * 2 + 2 << "\n";
    if (cnt == n - 1) {
      break;
    }
  }
  cout << 1 << " " << 3 + 4 * m << "\n";
}