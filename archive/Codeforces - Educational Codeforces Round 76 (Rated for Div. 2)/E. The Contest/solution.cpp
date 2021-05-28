#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int K1, K2, K3;
  cin >> K1 >> K2 >> K3;
  int N = K1 + K2 + K3;
  vector<int> p(N + 1);
  for (int i = 0; i < K1; i++) {
    int x;
    cin >> x;
    p[x] = 1;
  }
  for (int i = 0; i < K2; i++) {
    int x;
    cin >> x;
    p[x] = 2;
  }
  for (int i = 0; i < K3; i++) {
    int x;
    cin >> x;
    p[x] = 3;
  }
  vector<int> f(N + 2, 1e9);
  f[N + 1] = 0;
  int c2 = 0, c3 = 0;
  for (int i = N; i >= 1; i--) {
    if (p[i] == 3) {
      f[i] = min(f[i + 1] + 1, c2);
      c3++;
    } else if (p[i] == 2) {
      f[i] = f[i + 1];
      c2++;
    } else {
      f[i] = f[i + 1];
    }
  }
  int ans = 1e9;
  int c1 = 0;
  int other = 0;
  for (int i = 0; i <= N; i++) {
    c1 += (p[i] == 1);
    other += (i != 0 && p[i] != 1);
    ans = min(ans, K1 - c1 + other + f[i + 1]);
  }
  cout << ans << '\n';
}
