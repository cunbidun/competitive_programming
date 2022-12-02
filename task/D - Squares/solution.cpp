/**
 *  author: cunbidun
 *  created: Sunday, 2022-11-27 15:44:17 CST
 **/
#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long N, A, B;
    cin >> N >> A >> B;
    if (A < B) {
      swap(A, B);
    }
  }
}
