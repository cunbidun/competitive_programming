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
  long long mx = 0;
  for (int i = 1; i <= N; i++) {
    s[i] = s[i - 1] + a[i];
    mx = max(a[i], mx);
  }
  long long l = 0, r = mx;
  auto check = [&](int m) -> bool {
    long long u = 0;
    long long o = 0;
    for (int i = 1; i <= N; i++) {
      if (a[i] < m) {
        u += m - a[i];
      } else {
        o += a[i] - m;
      }
    }
    return u <= o;
  };
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  long long ans = 1e18;
  for (int i = 1; i <= N; i++) {
    long long o = (s[N] - s[i]) - a[i] * (N - i);
    long long u = a[i] * (i - 1) - s[i - 1];
    if (o < u) {
      ans = min(ans, A * (u - o) + C * o);
    } else {
      ans = min(ans, R * (o - u) + C * u);
    }
  }
  for (long long j = max(0LL, l - 5); j <= min(mx, l + 5); j++) {
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
