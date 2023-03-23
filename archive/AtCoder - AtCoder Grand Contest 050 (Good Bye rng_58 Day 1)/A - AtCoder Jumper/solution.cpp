/**
 *  author: cunbidun
 *  created: Tuesday, 2023-02-07 21:05:30 CST
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
  for (int i = 0; i < N; i++) {
    cout << (i * 2) % N + 1 << ' ' << (i * 2 + 1) % N + 1 << '\n';
  }
}
