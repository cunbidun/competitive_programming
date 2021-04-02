#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (a[(int)a.size() - 1] != x) {
      a.push_back(x);
    }
  }
  n = (int)a.size() - 1;
  vector<int> p(1e5 + 1, -1), l(1e5 + 1, -1), f(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    l[i] = p[a[i]];
    p[a[i]] = i;
  }
  f[1] = 1;
  int ans = 1e9;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] + (a[i] != a[i - 2]);
    if (l[i] != -1) {
      f[i] = min(f[i], f[l[i] + 1] + i - (l[i] + 1) - 1);
    }
    ans = min(ans, f[i] + n - i);
  }
  cout << ans << '\n';
}
