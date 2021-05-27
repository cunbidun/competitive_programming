#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  map<int, int> c;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    int s;
    cin >> s;
    ans -= i - c[s] - 1;
    ans += n - 1;
    c[s] = i;
    cout << ans << '\n';
  }
}
