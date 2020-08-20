#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, d, m, a[N];
vi l, g;
ll ans = 0;
ll sl[N], sg[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> d >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x <= m) {
      l.push_back(x);
    } else {
      g.push_back(x);
    }
  }
  sort(all(l), greater<int>());
  sort(all(g), greater<int>());
  sl[0] = 0;
  sg[0] = 0;
  for (int i = 0; i < sz(l); i++) {
    sl[i + 1] += sl[i] + l[i];
  }
  for (int i = 0; i < sz(g); i++) {
    sg[i + 1] += sg[i] + g[i];
  }

  for (int i = (sz(g) + d) / (d + 1); i <= min(sz(g), (n + d) / (d + 1)); i++) {
    int ncl = max(0, d * (i - 1) - (sz(g) - i));
    ans = max(ans, sg[i] + sl[sz(l) - ncl]);
  }
  cout << ans << "\n";
}
