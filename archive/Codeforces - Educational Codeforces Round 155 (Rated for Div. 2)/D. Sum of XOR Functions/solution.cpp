/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-24 10:02:45 CDT
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
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  long long ans = 0;
  for (int bit = 0; bit < 31; bit++) {
    long long base = 1 << bit;
    long long sum0 = 0, sum1 = 0;
    long long cnt0 = 1, cnt1 = 0;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
      int current = (a[i] >> bit) & 1;
      if (current == 1) {
        sum += 1LL * i * cnt0 - sum0;
        sum1 += i;
        cnt1++;
      } else {
        sum += 1LL * i * cnt1 - sum1;
        sum0 += i;
        cnt0++;
      }
      sum %= 998244353;
    }
    // cout << bit << ' ' << sum << '\n';
    ans = (ans + base * sum) % 998244353;
  }
  cout << ans << '\n';
}
