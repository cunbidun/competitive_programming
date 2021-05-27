#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, C;
    cin >> N >> C;
    vector<int> a;
    for (int i = 1; i <= N; i++) {
      a.push_back(i);
    }
    int ok = 0;
    do {
      vector<int> L = a;
      int ans = 0;
      for (int i = 0; i < N - 1; i++) {
        int mn = L[i], p = i;
        for (int j = i; j < N; j++) {
          if (mn > L[j]) {
            p = j;
            mn = L[j];
          }
        }
        ans += p - i + 1;
        reverse(L.begin() + i, L.begin() + p + 1);
      }
      if (ans == C) {
        for (int i : a) {
          cout << i << ' ';
        }
        cout << '\n';
        ok = 1;
        break;
      }
    } while (next_permutation(a.begin(), a.end()));
    if (!ok) {
      cout << "IMPOSSIBLE\n";
    }
  }
}
