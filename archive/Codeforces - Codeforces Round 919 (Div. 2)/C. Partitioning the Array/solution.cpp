#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
      cin >> A[i];
    int ans = 0;
    for (int k = 1; k < N; k++) {
      if (N % k == 0) {
        int gcd = 0;
        for (int i = k; i < N; i++) {
          gcd = __gcd(gcd, abs(A[i] - A[i - k]));
        }
        if (gcd != 1) {
          ans++;
        }
      }
    }
    cout << ans + 1 << '\n';
  }
}
