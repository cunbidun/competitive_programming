/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-24 09:09:31 CDT
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
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[N - 1]) {
      cout << -1 << '\n';
    } else {
      int cnt = 0;
      for (int i = N - 1; i >= 0; i--) {
        if (a[i] == a[N - 1]) {
          cnt++;
        }
      }
      cout << N - cnt << ' ' << cnt << "\n";
      for (int i = 0; i < N - cnt; i++) {
        cout << a[i] << ' ';
      }
      cout << '\n';
      for (int i = 0; i < cnt; i++) {
        cout << a[N - 1] << ' ';
      }
      cout << '\n';
    }
  }
}
