#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  vector<vector<int>> p(Q + 1, vector<int>(20));
  vector<int> a(Q + 1), c(Q + 1);
  auto jump = [&](int n) {
    for (int i = 19; i >= 0; i--) {
      if (a[p[n][i]] != 0) {
        n = p[n][i];
      }
    }
    return n;
  };
  cin >> a[0] >> c[0];
  for (int i = 1; i <= Q; i++) {
    int T;
    cin >> T;
    if (T == 1) {
      int P, A, C;
      cin >> P >> A >> C;
      p[i][0] = P;
      for (int j = 1; j < 20; j++) {
        p[i][j] = p[p[i][j - 1]][j - 1];
      }
      a[i] = A;
      c[i] = C;
    } else {
      long long ans = 0;
      long long cnt = 0;
      int W, A;
      cin >> W >> A;
      while (A > 0 && a[p[W][0]] != 0) {
        int par = jump(W);
        int mn = min(A, a[par]);
        A -= mn;
        a[par] -= mn;
        cnt += mn;
        ans += 1LL * c[par] * mn;
      }
      int mn = min(A, a[W]);
      A -= mn;
      a[W] -= mn;
      cnt += mn;
      ans += 1LL * c[W] * mn;
      cout << cnt << ' ' << ans << endl;
    }
  }
}
