#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  struct rule {
    int x, y, z;
  };

  vector<rule> rs;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    rs.push_back({x, y, z});
  }
  vector<long long> f((1 << n) + 5, -1);
  function<long long(int)> cal = [&](int s) {
    if (f[s] != -1) {
      return f[s];
    }
    vector<int> used;
    for (int i = 0; i < n; i++) {
      if (((s >> i) & 1) == 0) {
        used.push_back(i + 1);
      }
    }
    vector<int> l(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      l[i] = l[i - 1];
      if (cur < used.size() && i == used[cur]) {
        l[i]++;
        cur++;
      }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
      if ((s >> i) & 1) {
        int f = 0;
        for (auto r : rs) {
          if (r.x > used.size()) {
            if (r.y >= i + 1 && r.z < l[r.y] + 1) {
              f = 1;
              break;
            }
          }
        }
        if (!f) {
          res += cal(s ^ (1 << i));
        }
      }
    }
    return f[s] = res;
  };
  f[0] = 1;
  cout << cal((1 << n) - 1) << '\n';
}
