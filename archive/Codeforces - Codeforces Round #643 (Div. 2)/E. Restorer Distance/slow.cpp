#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long A, R, M;
  cin >> N >> A >> R >> M;
  long long C = min(A + R, M);
  vector<long long> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> s(N + 1);

  for (int i = 1; i <= N; i++) {
    s[i] = s[i - 1] + a[i];
  }

  long long ans = 1e18;
  for (int j = 0; j <= 1000; j++) {
    long long o = 0;
    long long u = 0;
    for (int i = 1; i <= N; i++) {
      if (a[i] > j) {
        o += a[i] - j;
      } else {
        u += j - a[i];
      }
    }
    if (o < u) {
      ans = min(ans, A * (u - o) + C * o);
    } else {
      ans = min(ans, R * (o - u) + C * u);
    }
  }
  cout << ans << '\n';
}
