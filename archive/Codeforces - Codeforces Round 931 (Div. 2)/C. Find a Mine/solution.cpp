#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  auto ask = [&](int x, int y) -> int {
    cout << "? " << x << " " << y << endl;
    int a;
    cin >> a;
    return a;
  };
  while (T--) {
    int N, M;
    cin >> N >> M;
    int d1 = ask(1, 1);
    int d2 = ask(N, M);
    int d3 = ask(1, M);

    int off = (d1 + d3 - M + 1);
    int r1 = -1;
    int c1 = -1;
    if (off % 2 == 0) {
      r1 = off / 2 + 1;
      c1 = d1 - off / 2 + 1;
    }
    int c2 = M + 1;
    int r2 = N + 1;
    off = (d2 + d3 - N + 1);
    if (off % 2 == 0) {
      c2 = M - off / 2;
      r2 = d3 - off / 2 + 1;
    }
    if (r1 <= 0) {
      cout << "! " << r2 << " " << c2 << endl;
    } else if (c2 > M) {
      cout << "! " << r1 << " " << c1 << endl;
    } else {
      int d4 = ask(r1, c1);
      if (d4 == 0) {
        cout << "! " << r1 << " " << c1 << endl;
      } else {
        cout << "! " << r2 << " " << c2 << endl;
      }
    }
  }
}
/*

2
3 5
1
1
1
5 3
1
1
1
*/
