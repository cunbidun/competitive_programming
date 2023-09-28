/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-24 09:43:30 CDT
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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> a(N), b(N);
    long long ans1 = 0;
    long long ans2 = 0;
    long long mn1 = 2e9, mn2 = 2e9;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      ans1 += a[i];
      mn1 = min(mn1, a[i]);
    }
    for (int i = 0; i < N; i++) {
      cin >> b[i];
      ans2 += b[i];
      mn2 = min(mn2, b[i]);
    }
    cout << min(mn2 * N + ans1, mn1 * N + ans2) << '\n';
  }
}
