/**
 * Slow file should read from stdin and print to stdout.
 *
 * We can think of this file as an correct but slower version
 * of the solution. It will be used to generate the correct
 * output.
 */

#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < (1 << N); j++) {
      int k = i + j;
      if (__builtin_popcount(i) + __builtin_popcount(j) == __builtin_popcount(k) + K) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}
