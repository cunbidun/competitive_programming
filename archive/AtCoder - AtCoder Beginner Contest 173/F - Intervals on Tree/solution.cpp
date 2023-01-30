/**
 *  author: cunbidun
 *  created: Wednesday, 2023-01-11 22:31:59 CST
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
  long long total = 0;
  for (long long i = 1; i <= N; i++) {
    total += i * (N - i + 1);
  }

  long long sub = 0;
  for (int i = 0; i < N - 1; i++) {
    long long u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    sub += u * (N - v + 1);
  }
  cout << total - sub << '\n';
}
