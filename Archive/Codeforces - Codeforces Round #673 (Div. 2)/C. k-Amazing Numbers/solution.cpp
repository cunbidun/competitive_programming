#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
int n, k, f[N];
vi a[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i].clear();
    f[i] = 2 * N;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (sz(a[i]) == 0) {
      continue;
    }
    int last = 0;
    int mx = a[i][0];
    for (int j = 0; j < sz(a[i]); j++) {
      mx = max(mx, a[i][j] - last);
      last = a[i][j];
    }
    mx = max(mx, n - last + 1);
    f[i] = mx;
  }
  int i = 1;
  vi ans;
  for (int k = n; k >= 1; k--) {
    while (i <= n && k < f[i]) {
      i++;
    }
    if (i == n + 1) {
      ans.push_back(-1);
      continue;
    }
    if (k >= f[i]) {
      ans.push_back(i);
    }
  }
  reverse(all(ans));
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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