/**
 *  created: Wednesday, 2023-09-13 22:52:02 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        if (gcd(max({a[i], a[j], a[k]}), min({a[i], a[j], a[k]})) == 1) {
          ans++;
        }
      }
    }
  }
  cout << ans << '\n';
}
