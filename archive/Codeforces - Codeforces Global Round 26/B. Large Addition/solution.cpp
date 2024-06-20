#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    auto solve = [&]() -> void {
      if (S[0] != '1') {
        cout << "NO\n";
        return;
      }
      if (S.back() == '9') {
        cout << "NO\n";
        return;
      }

      for (int i = 1; i < (int)S.size() - 1; i++) {
        if (S[i] == '0') {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
    };
    solve();
  }
}
