#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e3 + 1;
int n, m, a[N][N], ans[N][N];
vi r[N], c[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      r[i].push_back(a[i][j]);
      c[j].push_back(a[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    sort(all(r[i]));
    r[i].resize(unique(r[i].begin(), r[i].end()) - r[i].begin());
  }

  for (int i = 1; i <= m; i++) {
    sort(all(c[i]));
    c[i].resize(unique(c[i].begin(), c[i].end()) - c[i].begin());
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int gr = lower_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin();
      int gc = lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();
      int val = 1 + max(gr, gc);
      gr = upper_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin();
      gc = upper_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();
      cout << val + max(max(0, sz(r[i]) - gr), max(0, sz(c[j]) - gc)) << " ";
    }
    cout << "\n";
  }
}