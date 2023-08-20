/**
 *  author: cunbidun
 *  created: Sunday, 2023-07-23 16:26:12 CDT
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
  int N, K;
  cin >> N >> K;
  array<vector<vector<int>>, 2> c = {vector<vector<int>>(2e5 + 5), vector<vector<int>>(2e5 + 5)};
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    c[i % 2][a[i]].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (i >= N - K / 2 - 1) {
      break;
    }
    int starting = max(K / 2, i + 1);
    int ending = min(i + K - 1, N - 1) - K / 2;
    int lower = starting + (starting - i);
    int upper = ending + (ending - i);
    int num_eq = 0;
    auto it_lower = lower_bound(c[i % 2][a[i]].begin(), c[i % 2][a[i]].end(), lower);
    if (it_lower != c[i % 2][a[i]].end()) {
      auto it_upper = upper_bound(c[i % 2][a[i]].begin(), c[i % 2][a[i]].end(), upper);
      num_eq = it_upper - it_lower;
    }
    ans += (upper - lower) / 2 + 1 - num_eq;
  }
  cout << ans << '\n';
}
