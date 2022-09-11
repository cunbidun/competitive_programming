#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct mod_int {
  int MOD;
  mod_int(int MOD) { this->MOD = MOD; }
  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }
  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }
  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }
  int pow(int x, int p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }
  int inv(int x) { return pow(x, MOD - 2); }
  int div(int x, int y) { return mul(x, inv(y)); }
};

class PolygonColors {
public:
  mod_int mint{100000007};
  vector<int> a;

  vector<vector<int>> f{50, vector<int>(50, -1)};

  int solve(int l, int r) {
    if (f[l][r] != -1) {
      return f[l][r];
    }
    if (l + 1 == r) {
      return f[l][r] = 2;
    }
    int ans = solve(l, r - 1);
    for (int i = l + 1; i < r; i++) {
      if (a[i] != a[r]) {
        ans = mint.add(ans, mint.mul(solve(l, i), mint.div(solve(i, r), 2)));
      }
    }
    return f[l][r] = mint.mul(((a[l] != a[r]) + 1), ans);
  }

  int getWays(int N, vector<int> colors) {
    for (int i = 0; i < N; i++) {
      a.push_back(colors[i]);
      if (colors[i] == colors[(i + 1) % N]) {
        return 0;
      }
    }
    solve(0, N - 1);
    return mint.div(solve(0, N - 1), mint.pow(2, N));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // {
  //   int colors[] = {0, 1, 2};
  //   cout << PolygonColors().getWays(3, colors) << '\n';
  // }

  // {
  //   int colors[] = {1, 2, 3, 0};
  //   cout << PolygonColors().getWays(4, colors) << '\n';
  // }

  // {
  //   int colors[] = {1, 2, 1, 0};
  //   cout << PolygonColors().getWays(4, colors) << '\n';
  // }

  // {
  //   int colors[] = {0, 1, 2, 3, 4};
  //   cout << PolygonColors().getWays(5, colors) << '\n';
  // }
  // {
  //   int colors[] = {1, 2, 1, 2};
  //   cout << PolygonColors().getWays(4, colors) << '\n';
  // }

  // {
  //   int colors[] = {3, 1, 2, 1, 2, 1};
  //   cout << PolygonColors().getWays(6, colors) << '\n';
  // }

  // {
  //   int colors[] = {2, 1, 2, 1};
  //   cout << PolygonColors().getWays(4, colors) << '\n';
  // }

  // {
  //   int colors[] = {3, 1, 2, 1, 2, 1};
  //   cout << PolygonColors().getWays(6, colors) << '\n';
  // }

  //   int colors[] = {0, 1, 1, 1, 1};
  // {
  //   cout << PolygonColors().getWays(5, colors) << '\n';
  // }
  // {
  //   int colors[] = {0, 1, 2, 3, 4, 5};
  //   cout << PolygonColors().getWays(6, colors) << '\n';
  // }

  {
    vector<int> colors = {0, 1, 2, 6, 4, 5, 6, 7, 1, 9, 10, 11, 12, 13, 14, 10};
    cout << PolygonColors().getWays(colors.size(), colors) << '\n';
  }
}
