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
    cin >> N;
    cin >> S;
    int ans = 1;
    for (int i = (N - 1) / 2; i >= 1; i--) {
      if (S[i] == S[i - 1]) {
        ans++;
      } else {
        break;
      }
    }
    cout << ans * 2 - (N % 2) << '\n';
  }
}
