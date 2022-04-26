#include <algorithm>
#include <array>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<int> arr;
  for (int i = 0; i < 8; i++) {
    arr.push_back(i);
  }

  while (T--) {
    int cur = 4;
    while (cur != 0) {
      shuffle(arr.begin(), arr.end(), rng);
      string guess = "00000000";
      if (cur == 4) {
        for (int i = 0; i < 4; i++) {
          guess[arr[i]] = '1';
        }
      } else if (cur != 8) {
        for (int i = 0; i < cur; i++) {
          guess[arr[i]] = '1';
        }
      } else {
        guess = "11111111";
      }
      cout << guess << endl;
      cin >> cur;
      if (cur == -1) {
        exit(0);
      }
    }
  }
}
