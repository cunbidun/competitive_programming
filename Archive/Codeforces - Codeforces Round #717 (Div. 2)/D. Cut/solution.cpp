#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> lp;
  vector<int> pr;
  auto sieve = [&lp, &pr](int N) {
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j) {
        lp[i * pr[j]] = pr[j];
      }
    }
  };
  sieve(100001);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> pos(1e5 + 5, n);
  vector<vector<int>> p(n + 1, vector<int>(18));
  p[n][0] = n;
  for (int i = n - 1; i >= 0; i--) {
    int mn = n;
    vector<int> v;
    int tmp = a[i];
    while (tmp > 1) {
      v.push_back(lp[tmp]);
      int t = lp[tmp];
      while (tmp % t == 0) {
        tmp /= t;
      }
    }
    for (int j : v) {
      mn = min(pos[j], mn);
    }
    for (int j : v) {
      pos[j] = i;
    }
    p[i][0] = min(mn, p[i + 1][0]);
  }
  for (int i = 1; i < 18; i++) {
    for (int j = 0; j <= n; j++) {
      p[j][i] = p[p[j][i - 1]][i - 1];
    }
  }
  auto jump = [&](int i, int s) {
    for (int j = 17; j >= 0; j--) {
      if ((s >> j) & 1) {
        i = p[i][j];
      }
    }
    return i;
  };
  while (q--) {
    int s, e;
    cin >> s >> e;
    s--;
    e--;
    int l = 0, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (jump(s, m) > e) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << '\n';
  }
}
