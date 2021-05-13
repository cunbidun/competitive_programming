#include <bits/stdc++.h>

using namespace std;

vector<int> a = {0, 2, 3, 4, 5, 1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    auto ask = [](int t, int i, int j, int x) -> int {
      cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
      int res;
      cin >> res;
      return res;
    };
    int p = 0;
    for (int i = 2; i <= n + 1; i += 2) {
      if (i == n + 1) {
        i = n;
      }
      int res = ask(2, i - 1, i, 1);
      if (res == 2) {
        int r = ask(2, i, i - 1, 1);
        if (r == 1) {
          p = i;
          break;
        }
      } else if (res == 1) {
        p = i - 1;
        break;
      }
    }
    assert(p != 0);
    vector<int> ans(n + 1);
    ans[p] = 1;
    for (int i = 1; i <= n; i++) {
      if (i != p) {
        int res = ask(1, i, p, n - 1);
        if (res == n - 1) {
          int r = ask(1, p, i, n - 1);
          ans[i] = r;
        } else {
          ans[i] = res;
        }
      }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
}
