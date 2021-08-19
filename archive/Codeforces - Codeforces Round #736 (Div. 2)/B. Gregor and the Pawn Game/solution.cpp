#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    vector<int> c(2);
    vector<int> d(2);
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (a[i] == '0') {
        ans += min(d[0], c[1]) + min(d[1], c[0]);
        c.assign(2, 0);
        d.assign(2, 0);
        if (b[i] == '1') {
          ans++;
        }
      } else {
        if (b[i] == '1') {
          c[i % 2]++;
        }
        d[i % 2]++;
      }
    }
    ans += min(d[0], c[1]) + min(d[1], c[0]);
    cout << ans << '\n';
  }
}
