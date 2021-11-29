#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<long long> p(15);
  p[0] = 1;
  for (int i = 1; i <= 12; i++) {
    p[i] = 1LL * p[i - 1] * 10;
  }
  while (T--) {
    long long N, K;
    cin >> N >> K;
    K ++;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    vector<long long> num(N);
    for (int i = 0; i < N - 1; i++) {
      num[i] = min(K, (p[a[i + 1]] - p[a[i]]) / p[a[i]]);
      K -= min(K, (p[a[i + 1]] - p[a[i]]) / p[a[i]]);
    }
    num[N - 1] = K;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      ans += 1LL * num[i] * p[a[i]];
    }
    cout << ans << '\n';
  }
}
