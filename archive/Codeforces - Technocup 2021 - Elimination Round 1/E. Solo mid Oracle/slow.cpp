#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << '\n';
    } else {
      if (d >= c) {
        cout << a << '\n';
      } else {
        long long cur = 0;
        long long ans = 0;
        deque<int> q;
        for (int i = 0; i <= c; i++) {
          if (q.front() + c == i) {
            q.pop_front();
          }
          if (i % d == 0) {
            cur -= a;
            cur += b * (int)q.size();
            q.push_back(i + 1);
          } else {
            cur += b * (int)q.size();
          }
          ans = min(ans, cur);
        }
        cout << -ans << '\n';
      }
    }
  }
}
