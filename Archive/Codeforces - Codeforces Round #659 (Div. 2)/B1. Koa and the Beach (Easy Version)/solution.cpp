#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e2 + 2;
int a[N][N], ch[N][N], b[N];
int n, k, l;

int solve() {
  cin >> n >> k >> l;
  memset(ch, 0, sizeof(ch));
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int j = 0; j <= 2 * k - 1; j++) {
    for (int i = 1; i <= n; i++) {
      if (j <= k) {
        a[j][i] = b[i] + j;
      } else {
        a[j][i] = b[i] + 2 * k - j;
      }
    }
  }

  for (int i = 0; i <= 2 * k - 1; i++) {
    ch[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2 * k; j++) {
      if (j == 0) {
        if (ch[j][i] == 0 && ch[2 * k - 1][i - 1] == 1 && a[j][i] <= l) {
          ch[j][i] = 1;
          int cur = j;
          while (1) {
            if (a[cur][i] <= l && ch[cur][i] == 0) {
              ch[cur][i] = 1;
              cur++;
              if (cur == 2 * k) {
                cur = 0;
              }
            } else {
              break;
            }
          }
        }
        continue;
      }
      if (ch[j][i] == 0 && ch[j - 1][i - 1] == 1 && a[j][i] <= l) {
        ch[j][i] = 1;
        int cur = (j + 1) % (2 * k);
        while (1) {
          if (a[cur][i] <= l && ch[cur][i] == 0) {

            ch[cur][i] = 1;
            cur++;
            if (cur == 2 * k) {
              cur = 0;
            }
          } else {
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < 2 * k; i++) {
    if (ch[i][n] == 1) {
      cout << "Yes\n";
      return 0;
    }
  }
  // for (int j = 0; j <= 2 * k - 1; j++) {
  //   for (int i = 1; i <= n; i++) {
  //     cout << a[j][i] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  // for (int j = 0; j <= 2 * k - 1; j++) {
  //   for (int i = 1; i <= n; i++) {
  //     cout << ch[j][i] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << "No\n";
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