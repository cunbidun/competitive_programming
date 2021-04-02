#include <algorithm>
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
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
      cin >> L[i];
    }
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
    cout << ans << '\n';
  }
}
