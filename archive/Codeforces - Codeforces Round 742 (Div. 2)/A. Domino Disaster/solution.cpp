#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == 'L' || S[i] == 'R') {
        cout << S[i];
      }
      if (S[i] == 'U') {
        cout << 'D';
      }
      if (S[i] == 'D') {
        cout << 'U';
      }
    }
    cout << "\n";
  }
}
