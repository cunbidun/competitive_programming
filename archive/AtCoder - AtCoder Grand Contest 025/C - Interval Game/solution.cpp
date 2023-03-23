/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-12 21:50:59 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 2>> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  a.push_back({0, 0});
  N++;

  sort(a.begin(), a.end(), [](auto f, auto s) { return f[1] < s[1]; });
  long long ans = 0;
  int p = 0;
  map<int, int> lt, gt;
  for (int i = -1e5; i <= 1e5; i++) {
    while (p < N && a[p][1] <= i) {
      p++;
    }
    lt[i] = p;
  }

  sort(a.begin(), a.end());
  p = N - 1;
  for (int i = 1e5; i >= -1e5; i--) {
    while (p >= 0 && a[p][0] > i) {
      p--;
    }
    gt[i] = N - p - 1;
  }
  for (int i = -1e5; i <= 1e5; i++) {
    ans += min(lt[i], gt[i]) * 2;
  }
  cout << ans << '\n';
}
