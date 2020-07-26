#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int INF = 2e9;

vii a[N];
int n;
int tot = 0;
int cnt[N], cntd[N];

int dfs(int u, int l) {
  for (ii v : a[u])
    if (v.first != l) {
      if (v.second == 1) {
        tot++;
        cnt[v.first] = cnt[u] + 1;
        cntd[v.first] = cntd[u];
      }
      if (v.second == 0) {
        cnt[v.first] = cnt[u];
        cntd[v.first] = cntd[u] + 1;
      }
      dfs(v.first, u);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  rf(i, 1, n - 1) {
    int u, v;
    cin >> u >> v;
    a[u].pb({v, 0});
    a[v].pb({u, 1});
  }
  dfs(1, 1);
  int ans = INF;
  rf(i, 1, n) { ans = min(ans, tot - cnt[i] + cntd[i]); }
  cout << ans << "\n";
  rf(i, 1, n) {
    if (ans == tot - cnt[i] + cntd[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}