/**
 *  author: cunbidun
 *  created: Monday, 2023-01-16 20:25:37 CST
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
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes\n";
  auto cal = [&](int X, int x) -> vector<int> {
    int repeat = X / x;
    int remain = X % x;
    vector<int> res;
    res.push_back(repeat + 1);
    for (int i = 2; i <= remain; i++) {
      res.push_back(0);
    }
    res.push_back(-(repeat + 2));
    for (int i = remain + 2; i <= x; i++) {
      res.push_back(0);
    }
    vector<int> to_return;
    int cur = 0;
    for (int i = 0; i < X; i++) {
      to_return.push_back(res[cur]);
      cur = (cur + 1) % x;
    }
    return to_return;
  };
  if (H % h != 0) {
    vector<int> res = cal(H, h);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cout << res[i] << ' ';
      }
      cout << '\n';
    }
  } else {
    vector<int> res = cal(W, w);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cout << res[j] << ' ';
      }
      cout << '\n';
    }
  }
}
