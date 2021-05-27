#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;

int s[4 * N];
void update(int i, int l, int r, int p, int v) {
  if (l > p || r < p) {
    return;
  }
  if (l == p && l == r) {
    s[i] = max(s[i], v);
    return;
  }
  int m = (l + r) / 2;
  update(i * 2, l, m, p, v);
  update(i * 2 + 1, m + 1, r, p, v);
  s[i] = max(s[i * 2], s[i * 2 + 1]);
}

int get_max(int i, int l, int r, int L, int R) {
  if (l > r || l > R || L > r) {
    return 0;
  }
  if (L <= l && r <= R) {
    return s[i];
  }
  int m = (l + r) / 2;
  return max(get_max(i * 2, l, m, L, R), get_max(i * 2 + 1, m + 1, r, L, R));
}

int n, k, a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int mn = 3e5 + 1;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
  }
  int ans = 0;
 
  for (int i = 1; i <= n; i++) {
    int cur = get_max(1, 1, mn, max(1, a[i] - k), min(mn, a[i] + k)) + 1;
    ans = max(ans, cur);
    update(1, 1, mn, a[i], cur);
  }
  cout << ans << "\n";
}
