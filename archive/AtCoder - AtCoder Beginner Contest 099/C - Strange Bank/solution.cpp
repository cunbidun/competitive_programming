/**
 *  author: cunbidun
 *  created: Saturday, 2022-12-17 13:59:27 CST
 **/
#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> f(N + 1, 1e9);
  f[0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int p : {6, 9}) {
      int cur = 1;
      while (cur <= i) {
        f[i] = min(f[i], f[i - cur] + 1);
        cur *= p;
      }
    }
  }
  cout << f[N] << '\n';
}
