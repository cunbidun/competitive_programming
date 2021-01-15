#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N], mx[N], rmq[N][20];

int cal(int l, int r) {
  int k = log2(r - l + 1);
  return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  mx[n + 1] = 0;

  for (int i = 1; i <= n; i++) {
    mx[i] = 0;
    for (int j = 0; j <= 18; j++) {
      rmq[i][j] = 1e9;
    }
  }
  for (int i = 1; i <= n; i++) {
    rmq[i][0] = a[i];
  }
  for (int i = n; i >= 1; i--) {
    mx[i] = max(mx[i + 1], a[i]);
  }
  for (int i = 1; i <= 18; i++) {
    for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
      rmq[j][i] = min(rmq[j][i - 1], rmq[j + (1 << (i - 1))][i - 1]);
    }
  }
  int tar = 0;
  for (int x = 1; x <= n - 2; x++) {
    tar = max(tar, a[x]);
    int l = x + 2, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (mx[m] > tar) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    int f = l;
    if (mx[f] != tar) {
      continue;
    }
    l = x + 2, r = n;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (mx[m] < tar) {
        r = m - 1;
      } else {
        l = m;
      }
    }
    int s = l;
    l = f - 1;
    r = s - 1;
    while (l < r) {
      int m = (r + l) / 2;
      if (cal(x + 1, m) == tar) {
        cout << "YES\n";
        cout << x << " " << m - x << " " << n - m << "\n";
        return;
      }
      if (cal(x + 1, m) > tar) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (cal(x + 1, l) == tar) {
      cout << "YES\n";
      cout << x << " " << l - x << " " << n - l << "\n";
      return;
    }
  }

  cout << "NO\n";
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
