/**
 *  author: cunbidun
 *  created: Monday, 2023-05-22 21:49:05 CDT
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
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u] |= 1 << v;
    a[v] |= 1 << u;
  }
  vector<int> f(1 << N, 100);
  f[0] = 0;

  for (int mask = 1; mask < (1 << N); mask++) {
    int fail = 0;
    for (int i = 0; i < N; i++) {
      if (((mask >> i) & 1) && (mask & a[i]) != (mask ^ (1 << i))) {
        fail = 1;
        break;
      }
    }
    if (!fail) {
      f[mask] = 1;
    }
  }

  for (int mask = 1; mask < (1 << N); mask++) {
    for (int submask = mask; --submask &= mask;) {
      f[mask] = min(f[mask], f[submask ^ mask] + f[submask]);
    }
  }
  cout << f[(1 << N) - 1];
}
