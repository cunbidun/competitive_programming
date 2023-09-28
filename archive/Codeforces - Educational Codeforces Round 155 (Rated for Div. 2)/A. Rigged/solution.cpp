/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-24 09:36:07 CDT
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
    vector<int> s(N), e(N);
    for (int i = 0; i < N; i++) {
      cin >> s[i] >> e[i];
    }
    int f = 1;
    for (int i = 1; i < N; i++) {
      if (s[i] >= s[0] && e[i] >= e[0]) {
        f = 0;
      }
    }
    if (!f) {
      cout << -1 << '\n';
    } else {
      cout << s[0] << '\n';
    }
  }
}
