/**
 *  author: cunbidun
 *  created: Thursday, 2023-08-17 18:58:12 CDT
 **/
#include <array>
#include <assert.h>
#include <bitset>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  /*
   * let f[i][j] = 1 if consider the first ith elements, pick a valid subset that sum equal to j
   * valid means the subset has to reachable
   *
   * We have f[i][j] = f[i - 1][j] | f[i - 1][j - a[i]] if j - a[i] >= i
   *    else f[i][j] = f[i - 1][j]
   *
   * Here we can see that for each i, all the j is "shifted" by a[i], so bitset can be use to optimize
   *
   * Let f[i] = the bitset of reachable states (set to 1) if we only consider the first ith elements
   * f[i] = f[i - 1] | f[i - 1] << a[i];
   *
   * to make sure j - a[i] >= i holds, after ith iterations, we will clear ith elements of the set
   * */
  vector<int> a(2 * N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  for (int i = N + 1; i <= 2 * N; i++) {
    a[i] = 0;
  }
  vector<bitset<(int)2e5 + 5>> f(2);
  f[0][1] = 1;
  long long sum = 0;
  long long ans = 0;
  for (int i = 1; i <= 2 * N; i++) {
    int current = i % 2;
    int last = 1 - current;
    f[current] = f[last] | (f[last] << a[i]);
    sum += a[i];
    if (f[current][i] == 1) {
      ans = max(ans, sum - i + 1);
    }
    f[current][i] = 0;
  }
  cout << ans << '\n';
}
