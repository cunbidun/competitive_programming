#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, q, a[N], g[N][18], lg[N];
map<int, ll> ans;

int precal() {
  for (int i = 1; i <= n; i++) {
    g[i][0] = a[i];
  }
  for (int j = 1; j <= 17; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    lg[i] = log2(i);
  }
}

int get_gcd(int l, int r) {
  int k = lg[(r - l + 1)];
  return __gcd(g[l][k], g[r - (1 << k) + 1][k]);
}

int find_next(int i, int v) {
  int l = i, r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (get_gcd(i, m) >= v) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  precal();

  for (int i = 1; i <= n; i++) {
    int p = i;
    while (p <= n) {
      int cur = get_gcd(i, p);
      int nxt = find_next(i, cur);
      ans[cur] += 1ll * (nxt - p + 1);
      p = nxt + 1;
    }
  }
  
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    cout << ans[x] << "\n";
  }
}