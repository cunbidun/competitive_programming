#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int MOD = 998244353;
  int ans = 1;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (a[i] < a[j]) {
        cnt++;
      }
    }
    if (cnt == K) {
      ans = (1LL * ans * (N - i)) % MOD;
    }
  }
  cout << ans << '\n';
}
