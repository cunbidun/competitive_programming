#include <bits/stdc++.h>

using namespace std;

class PowersOfTwo {
public:
  long long count(vector<long long> powers) {
    vector<int> a(70);
    for (long long p : powers) {
      int cnt = 0;
      while (p) {
        p /= 2;
        cnt++;
      }
      cnt--;
      a[cnt]++;
    }
    vector<vector<long long>> f(75, vector<long long>(1000, -1));
    function<long long(int, int)> cal = [&](int i, int c) {
      long long res = f[i][c];
      if (res == -1) {
        if (i == a.size()) {
          res = 1;
        } else {
          int cur = a[i] + c;
          res = cal(i + 1, cur / 2);
          if (cur > 0) {
            res += cal(i + 1, (cur - 1) / 2);
          }
        }
      }
      return f[i][c] = res;
    };
    cout << cal(0, 0) << '\n';
    return cal(0, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  PowersOfTwo m;
  m.count({1, 2});
  m.count({1, 1, 1, 1});
  m.count({1, 2, 2, 2, 4, 4, 16});
  m.count({1, 32, 1, 16, 32});
  m.count({1048576, 1073741824, 549755813888, 70368744177664, 4398046511104, 262144, 1048576, 2097152, 8796093022208, 1048576, 1048576, 35184372088832, 2097152, 256, 256, 256, 262144, 1048576, 1048576, 70368744177664, 262144, 1048576});
}
