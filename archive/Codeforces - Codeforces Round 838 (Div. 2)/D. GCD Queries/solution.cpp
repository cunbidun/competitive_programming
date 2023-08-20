/**
 *  author: cunbidun
 *  created: Saturday, 2023-06-10 09:39:52 CDT
 **/
#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto answer = [&](int i, int j) {
    cout << "! " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    if (res == -1) {
      exit(0);
    }
    return;
  };
  auto ask = [&](int i, int j) -> int {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int x;
    cin >> x;
    return x;
  };

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> candidate;
    for (int i = 0; i < N; i++) {
      candidate.push_back(i);
    }

    while (candidate.size() > 2) {
      int i = candidate.back();
      candidate.pop_back();
      int j = candidate.back();
      candidate.pop_back();
      int k = candidate.back();
      candidate.pop_back();
      int x = ask(i, j);
      int y = ask(i, k);
      if (x == y) {
        candidate.push_back(j);
        candidate.push_back(k);
      } else if (x > y) {
        candidate.push_back(i);
        candidate.push_back(j);
      } else {
        candidate.push_back(i);
        candidate.push_back(k);
      }
    }
    answer(candidate[0], candidate[1]);
  }
}
