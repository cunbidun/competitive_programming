#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e3 + 3;
int n, a[N][N];
int rl[N][10], rr[N][10], ch[N][10], cl[N][10];
int u[10], d[10], l[10], r[10], ans[10];
void solve() {
  cin >> n;
  for (int i = 0; i <= 9; i++) {
    u[i] = N;
    d[i] = 0;
    l[i] = N;
    r[i] = 0;
    ans[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      rl[i][j] = N;
      rr[i][j] = 0;
      ch[i][j] = N;
      cl[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
      u[a[i][j]] = min(u[a[i][j]], i);
      d[a[i][j]] = max(d[a[i][j]], i);
      l[a[i][j]] = min(l[a[i][j]], j);
      r[a[i][j]] = max(r[a[i][j]], j);
      rl[i][a[i][j]] = min(rl[i][a[i][j]], j);
      rr[i][a[i][j]] = max(rr[i][a[i][j]], j);
      ch[j][a[i][j]] = min(ch[j][a[i][j]], i);
      cl[j][a[i][j]] = max(cl[j][a[i][j]], i);
    }
  }
  for (int i = 0; i < 10; i++) {
    if (l[i] == r[i] && u[i] == d[i]) {
      continue;
    }
    for (int j = 1; j <= n; j++) {
      if (rl[j][i] == N) {
        continue;
      }
      if (rl[j][i] != rr[j][i]) {
        ans[i] = max(ans[i], (rr[j][i] - rl[j][i]) * max(j - 1, n - j));
      }
      ans[i] = max(ans[i], max(n - rl[j][i], rr[j][i] - 1) * max(j - u[i], d[i] - j));
    }
    for (int j = 1; j <= n; j++) {
      if (ch[j][i] == N) {
        continue;
      }
      if (ch[j][i] != cl[j][i]) {
        ans[i] = max(ans[i], (cl[j][i] - ch[j][i]) * max(j - 1, n - j));
      }
      ans[i] = max(ans[i], max(n - ch[j][i], cl[j][i] - 1) * max(j - l[i], r[i] - j));
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}