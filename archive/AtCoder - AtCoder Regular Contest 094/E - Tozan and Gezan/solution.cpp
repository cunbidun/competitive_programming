/**
 *  author: cunbidun
 *  created: Sunday, 2023-05-14 13:57:45 CDT
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
  vector<int> a(N), b(N);
  long long sum = 0;
  int INF = 2e9;
  int mn = INF;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    sum += a[i];
    if (a[i] > b[i]) {
      mn = min(mn, b[i]);
    }
  }
  if (mn == INF) {
    cout << 0 << '\n';
  } else {
    cout << sum - mn << "\n";
  }
}
