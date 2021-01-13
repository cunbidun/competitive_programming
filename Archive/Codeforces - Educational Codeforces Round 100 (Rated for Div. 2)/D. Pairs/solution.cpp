#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, a[N], b[N];

int check(int m) {
  for (int i = 1; i <= m; i++) {
    if (b[i] > a[i + n - m]) {
      return 0;
    }
  }
  for (int i = m + 1; i <= n; i++) {
    if (b[i] < a[i - m]) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    s.insert(b[i]);
  }
  int cnt = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (s.find(i) == s.end()) {
      a[cnt++] = i;
    }
  }
  assert(cnt == n + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] < a[i]) {
      x++;
    }
  }
  int l = 0, r = x;
  while (l != r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int l0 = l;
  l = x, r = n;
  while (l != r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l - l0 + 1 << "\n";
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
