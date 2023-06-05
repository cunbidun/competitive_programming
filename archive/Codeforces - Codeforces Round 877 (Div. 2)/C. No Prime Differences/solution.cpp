/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-04 10:24:19 CDT
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
    int N, M;
    cin >> N >> M;
    vector<int> o, e;
    for (int i = 0; i < N; i++) {
      if (i % 2 == 1) {
        o.push_back(i);
      } else {
        e.push_back(i);
      }
    }
    for (int i : o) {
      for (int j = 1; j <= M; j++) {
        cout << j + i * M << ' ';
      }
      cout << '\n';
    }

    for (int i : e) {
      for (int j = 1; j <= M; j++) {
        cout << j + i * M << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }
}
