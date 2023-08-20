/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-18 09:35:54 CDT
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
    vector<int> cnt(1000);
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int f = 0;
    for (int i = 1; i < 1000; i++) {
      if (cnt[i] > cnt[i - 1]) {
        f = 1;
        break;
      }
    }
    cout << (!f ? "YES" : "NO") << '\n';
  }
}
