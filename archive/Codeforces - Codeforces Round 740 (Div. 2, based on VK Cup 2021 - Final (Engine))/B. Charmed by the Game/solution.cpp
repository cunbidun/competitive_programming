#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    set<int> ans;
    auto solve = [&](int A, int B) {
      int mx = min(A, b) + min(B, a);
      int cur = min(min(A, b), min(B, a));
      ans.insert(mx);
      while (cur--) {
        mx -= 2;
        ans.insert(mx);
      }
    };

    solve((a + b) / 2, a + b - (a + b) / 2);
    solve(a + b - (a + b) / 2, (a + b) / 2);

    cout << ans.size() << '\n';
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
