#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e15;
int n;
int a[5005];
int b[5005];
ll f[2][5005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);

  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = INF;
    }
  }

  for (int i = 1; i <= n; i++) {
    f[1][i] = abs(a[1] - b[i]);
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[0][j] = f[1][j];
      f[1][j] = INF;
    }

    ll l[5005];
    for (int j = 0; j <= n; j++) {
      l[j] = INF;
    }
    for (int j = 1; j <= n; j++) {
      l[j] = min(l[j - 1], f[0][j]);
    }
    for (int j = 1; j <= n; j++) {
      f[1][j] = l[j] + abs(a[i] - b[j]);
    }

  }

  ll ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, f[1][i]);
  }
  cout << ans << "\n";
}