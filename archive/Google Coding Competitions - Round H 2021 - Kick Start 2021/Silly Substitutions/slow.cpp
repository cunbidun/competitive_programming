#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
      char c;
      cin >> c;
      S[i] = c - '0';
    }
    while (1) {
      int changed = 0;
      if (S.size() == 1) {
        break;
      }
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < (int)S.size() - 1; j++) {
          if (S[j] == i && S[j + 1] == (i + 1) % 10) {
            S.erase(S.begin() + j);
            S[j]++;
            S[j] %= 10;
            changed = 1;
          }
        }
      }
      if (!changed) {
        break;
      }
    }
    for (int i : S) {
      cout << i;
    }
    cout << '\n';
  }
}
