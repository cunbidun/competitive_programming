#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e6 + 5;
int n, m, b, s, p, a[N];
ll f[N][3], INF = 1e17;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> p >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i][0] = INF;
    f[i][1] = INF;
    f[i][2] = INF;
  }
  sort(a + 1, a + n + 1);
  f[1][0] = s;
  f[1][1] = p;
  int l = 1;
  for (int i = 2; i <= n; i++) {
    while ((a[i] - a[l]) >= m) {
      l++;
    }
    f[i][0] = min(f[i][0], min(f[i - 1][0], f[l][1]) + s);
    f[i][1] = min(f[i][1], min(f[i - 1][0], f[l][1]) + p);
    f[i][0] = min(f[i][0], f[i - 1][2] + s);
    f[i][1] = min(f[i][1], f[i - 1][2] + p);
    f[i][2] = min(f[i][2], f[l][1]);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << f[i][0] << " " << f[i][1] << "\n";
  // }
  // cout << "\n";
  cout << min(min(f[n][0], f[n][1]), f[n][2]) << "\n";
}
