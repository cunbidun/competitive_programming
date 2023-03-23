/**
 *  author: cunbidun
 *  created: Saturday, 2023-02-25 19:38:16 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
int main() {
  long long N, K;
  cin >> N >> K;
  long long ans = 0;
  for (long long i = 1; i <=N; i++) {
    long long x = i;
    long long p = 1;
    while (x) {
      p *= x % 10;
      x /= 10;
    }
    if (p <= K) {
      // cout << i <<  ' '  << p << '\n';
      ans++;
    }
  }
  cout << ans << '\n';
}
