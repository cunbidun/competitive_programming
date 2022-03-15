#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long MOD = 100000001209;
  int MX = 1000000;
  vector<long long> p(MX + 1);
  p[0] = 1;
  for (int i = 1; i <= MX; i++) {
    p[i] = (p[i - 1] * 2) % MOD;
  }

  int N;
  cin >> N;
  vector<int> cnt(MX + 1);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  vector<long long> num_set(MX + 1);
  for (int i = MX; i >= 1; i--) {
    long long tot = cnt[i];
    long long bigger = 0;
    for (int j = 2; i * j <= MX; j++) {
      tot = tot + cnt[i * j];
      bigger = bigger + num_set[i * j];
    }
    num_set[i] = ((p[tot] - 1 - bigger) % MOD + MOD) % MOD;
    // if (i == 15) {
    //   cout << tot << '\n';
    //   cout << bigger << '\n';
    //   cout << num_set[i] << '\n';
    // }
    if (num_set[i] != 0) {
      // cout << i << ' ' << num_set[i] << '\n';
      ans++;
    }
  }
  cout << ans - N << '\n';
}
