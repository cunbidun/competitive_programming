/**
 *  author: cunbidun
 *  created: Saturday, 2022-12-17 21:42:59 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N), f(N), cnt(N + 2);
  int pos = 1;
  int new_value = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a[i] = min(x, pos);
    if (i >= 2) {
      if (a[i - 2] == a[i - 1] - 1) {
        if (!new_value) {
          a[i] = a[i - 1] + 1;
          new_value = 1;
        } else {
          new_value = 0;
        }
      }
    }
    pos = a[i] + 2;
  }

  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < N; i++) {
    if (a[i - 2] == a[i - 1] - 1) {
      f[i] = f[i - 2] + 1;
    } else {
      f[i] = f[i - 1];
    }
  }
  for (int i = 0; i < N; i++) {
    cnt[f[i]]++;
  }

  const int MOD = 1e9 + 7;
  int ans = 1;
  for (int i = 1; i <= N; i++) {
    ans = (1LL * ans * cnt[i]) % MOD;
    cnt[i + 1] += max(0, cnt[i] - 1);
  }
  cout << ans << '\n';
}
