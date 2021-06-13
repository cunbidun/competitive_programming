#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<long long> l(N + 2), r(N + 2);
  vector<long long> sc(N + 1);
  for (int i = 1; i <= N; i++) {
    sc[i] = sc[i - 1] + a[i];
    l[i] = l[i - 1];
    if (a[i] > 0) {
      l[i] += a[i];
    }
  }
  for (int i = N; i >= 1; i--) {
    r[i] = r[i + 1];
    if (a[i] > 0) {
      r[i] += a[i];
    }
  }

  long long ans = 0;
  for (int i = K; i <= N; i++) {
    ans = max(ans, sc[i] - sc[i - K] + l[i - K] + r[i + 1]);
    ans = max(ans, l[i - K] + r[i + 1]);
  }
  cout << ans << '\n';
}
