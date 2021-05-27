#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n1, n2, n3, n4;
  cin >> n1 >> n2 >> n3 >> n4;
  vector<int> a1(n1);
  vector<int> a2(n2);
  vector<int> a3(n3);
  vector<int> a4(n4);
  for (int i = 0; i < n1; i++) {
    cin >> a1[i];
  }
  for (int i = 0; i < n2; i++) {
    cin >> a2[i];
  }
  for (int i = 0; i < n3; i++) {
    cin >> a3[i];
  }
  for (int i = 0; i < n4; i++) {
    cin >> a4[i];
  }
  int m1, m2, m3;
  cin >> m1;
  vector<pair<int, int>> p1(m1);
  for (int i = 0; i < m1; i++) {
    cin >> p1[i].first >> p1[i].second;
  }
  cin >> m2;
  vector<pair<int, int>> p2(m2);
  for (int i = 0; i < m2; i++) {
    cin >> p2[i].first >> p2[i].second;
  }
  cin >> m3;
  vector<pair<int, int>> p3(m3);
  for (int i = 0; i < m3; i++) {
    cin >> p3[i].first >> p3[i].second;
  }
  auto f = [](vector<int> x, vector<int> y, vector<pair<int, int>> r) {
    int sx = (int)x.size();
    int sy = (int)y.size();
    vector<pair<int, int>> px;
    for (int i = 0; i < sx; i++) {
      px.push_back({x[i], i});
    }
    sort(px.begin(), px.end());
    vector<int> order(sx);
    for (int i = 0; i < sx; i++) {
      order[px[i].second] = i;
    }
    vector<vector<int>> l(sy, vector<int>());
    for (auto [f, s] : r) {
      l[s - 1].push_back(order[f - 1]);
    }
    for (int i = 0; i < sy; i++) {
      sort(l[i].begin(), l[i].end());
      int cnt = 0;
      for (int i : l[i]) {
        if (i != cnt) {
          break;
        } else {
          cnt++;
        }
      }
      if (cnt >= sx) {
        y[i] = 5e8;
      } else {
        y[i] += px[cnt].first;
      }
    }
    return y;
  };
  a2 = f(a1, a2, p1);
  a3 = f(a2, a3, p2);
  a4 = f(a3, a4, p3);
  int ans = 2e9;
  for (int i : a4) {
    ans = min(ans, i);
  }
  if (ans > 4e8) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
