#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<long long> d(N);
  for (int i = 0; i < M; i++) {
    int U, V, D;
    cin >> U >> V >> D;
    U--, V--;
    d[U] -= D;
    d[V] += D;
  }
  vector<pair<long long, int>> p, n;
  for (int i = 0; i < (int)d.size(); i++) {
    if (d[i] > 0) {
      p.push_back({d[i], i});
    } else if (d[i] < 0) {
      n.push_back({d[i], i});
    }
  }
  int cur = 0;
  vector<array<long long, 3>> ans;
  for (int i = 0; i < (int)n.size(); i++) {
    long long mn = min(p[cur].first, abs(n[i].first));
    ans.push_back({n[i].second, p[cur].second, mn});
    p[cur].first -= mn;
    n[i].first += mn;
    if (p[cur].first == 0) {
      cur++;
    }
    if (n[i].first != 0) {
      i--;
    }
  }
  cout << ans.size() << '\n';
  for (auto e : ans) {
    cout << e[0] + 1 << ' ' << e[1] + 1 << ' ' << e[2] << '\n';
  }
}
