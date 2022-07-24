#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  int MOD = 1e9 + 7;
  map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    int x;
    cin >> x;
    while (x % Q == 0) {
      x /= Q;
      cnt++;
    }
    if (mp.find(x) == mp.end()) {
      mp[x] = vector<int>();
    }
    mp[x].push_back(cnt);
  }
  vector<int> ans(N);
  for (auto [x, a] : mp) {
    vector<vector<int>> f(40, vector<int>(40));
    for (int i : a) {
      f[i][0]++;
      for (int j = 1; j <= i; j++) {
        f[i][j] = (f[i][j] + f[i - 1][j - 1]) % MOD;
      }
    }
    for (int i = 0; i <= 35; i++) {
      for (int j = 0; j <= 35; j++) {
        ans[j] = (ans[j] + f[i][j]) % MOD;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
