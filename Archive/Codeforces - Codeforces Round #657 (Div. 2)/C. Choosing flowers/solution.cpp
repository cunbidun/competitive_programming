#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, m;
vi l;
ll a[N], b[N], ans = 0, sum[N];

int solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    l.push_back(a[i]);
  }
  l.push_back(0);
  sort(all(l));
  sum[0] = l[0];
  for (int i = 1; i < sz(l); i++) {
    sum[i] = sum[i - 1] + l[i];
  }

  for (int i = 1; i <= m; i++) {
    ll res = a[i] + b[i] * (n - 1);
    int num = upper_bound(all(l), b[i]) - l.begin();
    if (num == sz(l)) {
      ans = max(ans, res);
      continue;
    }
    int num_replace = min(n - 1, m - num + 1);
    ll cur = sum[m] - sum[m - num_replace];
    if (a[i] >= l[m - num_replace + 1]) {
      cur -= a[i];
      if (l[m - num_replace] > b[i]) {
        cur += l[m - num_replace];
      } else {
        num_replace--;
      }
    }
    ans = max(res - num_replace * b[i] + cur, ans);
  }
  cout << ans << "\n";

  l.clear();
  ans = 0;
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