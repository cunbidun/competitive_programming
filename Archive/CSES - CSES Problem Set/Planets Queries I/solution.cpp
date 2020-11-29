#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, q, d[N], jump[N][31];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    jump[i][0] = d[i];
  }
  for (int j = 1; j <= 30; j++) {
    for (int i = 1; i <= n; i++) {
      jump[i][j] = jump[jump[i][j - 1]][j - 1];
    }
  }
  while (q--) {
    int x, k;
    cin >> x >> k;
    for (int i = 30; i >= 0; i--) {
      if (((k >> i) & 1) == 1) {
        x = jump[x][i];
      }
    }
    cout << x << "\n";
  }
}