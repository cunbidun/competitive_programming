#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, x, ans;
inline int f(int x, int y) { return (y - x % y) * (x / y) * (x / y) + x % y * (x / y + 1) * (x / y + 1); }
struct node {
  int x, y;
  bool operator<(const node &w) const { return f(x, y + 1) - f(x, y) > f(w.x, w.y + 1) - f(w.x, w.y); }
};
priority_queue<node> q;
signed main() {
  cin >> n >> m;
  m -= n;
  for (int i = 1; i <= n; i++)
    cin >> x, ans += x * x, q.push((node){x, 1});
  for (int i = 1; i <= m; i++) {
    int x = q.top().x, y = q.top().y;
    q.pop();
    ans = ans - f(x, y) + f(x, y + 1);
    q.push((node){x, y + 1});
  }
  printf("%lld\n", ans);
}
