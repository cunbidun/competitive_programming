#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, q, a[N], p[N], b[N][20], l[N], pp[N], s[N], rmq[N][20];

int get_max(int left, int right) {
  int k = log2(right - left + 1);
  return max(rmq[left][k], rmq[right - (1 << k) + 1][k]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    pp[p[i]] = i;
  }
  p[0] = p[n];
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    int j = pp[a[i]] - 1;
    b[i][0] = l[p[j]];
    l[a[i]] = i;
  }
  for (int j = 1; j <= 19; j++) {
    for (int i = 1; i <= m; i++) {
      b[i][j] = b[b[i][j - 1]][j - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    int cur = i;
    for (int j = 19; j >= 0; j--) {
      if ((((n - 1) >> j) & 1) == 1) {
        cur = b[cur][j];
      }
    }
    rmq[i][0] = cur;
  }
  for (int j = 1; j <= 19; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= m; i++) {
      rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
  }
  while (q--) {
    int left, right;
    cin >> left >> right;
    cout << ((get_max(left, right) >= left) ? 1 : 0);
  }
  cout << '\n';
}