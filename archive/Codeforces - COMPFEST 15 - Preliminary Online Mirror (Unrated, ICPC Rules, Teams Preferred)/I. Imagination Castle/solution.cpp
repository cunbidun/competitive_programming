/**
 *  author: cunbidun
 *  created: Thursday, 2023-09-28 20:58:34 CDT
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
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> r(N + 1), c(M + 1);
  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    r[x] = max(r[x], y);
    c[y] = max(c[y], x);
  }
  int x = N, y = M;
  if (r[1] || c[1]) {
    cout << "Chaneka" << '\n';
    return 0;
  }

  while (true) {
    if (x == 1 || y == 1) {
      break;
    }
    if (y <= r[x] && x <= c[y]) {
      x--;
      y--;
    } else if (y <= r[x]) {
      x--;
    } else if (x <= c[y]) {
      y--;
    } else {
      x--;
      y--;
    }
  }
  while (y <= r[x] && x > 1) {
    x--;
  }
  while (x <= c[y] && y > 1) {
    y--;
  }
  if (x == 1 && y == 1) {
    cout << "Bhinneka" << '\n';
  } else {
    cout << "Chaneka" << '\n';
  }
}
