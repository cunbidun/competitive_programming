#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long n2, n3, n4;
    cin >> n2 >> n3 >> n4;
    long long ans = 0;
    long long mn = (min(n3 / 2, n4));
    n3 -= mn * 2;
    n4 -= mn;
    ans += mn;

    mn = (min(n4 / 2, n2));
    n4 -= mn * 2;
    n2 -= mn;
    ans += mn;

    mn = (min(n4, n2 / 3));
    n4 -= mn;
    n2 -= mn * 3;
    ans += mn;

    mn = (min(n3 / 2, n2 / 2));
    n3 -= mn * 2;
    n2 -= mn * 2;
    ans += mn;

    ans += n2 / 5;
    cout << ans << '\n';
  }
}
