/**
 *  author: cunbidun
 *  created: Tuesday, 2022-12-27 22:08:51 CST
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
    if (N % 2 == 0) {
      bool f = 0;
      for (int i = 0; i < (int)a.size(); i += 2) {
        f |= (a[i] != a[i + 1]);
      }
      if (f) {
        cout << "First\n";
      } else {
        cout << "Second\n";
      }
    } else {
      cout << "Second\n";
    }
  }
}
