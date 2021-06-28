#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 2>> e;
  vector<array<int, 2>> o;
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    o.push_back({x, 2 * i - 1});
    e.push_back({x, 2 * i});
  }
  sort(o.begin(), o.end(), [](auto a, auto b) {
    return a[0] > b[0];
  });
  vector<set<int>> ans(2 * N + 1);
  vector<int> w(N + 1);
  auto add = [&](int u, int v) {
    ans[u].insert(v);
    ans[v].insert(u);
  };
  for (int i = 1; i < N; i++) {
    add(o[i][1], o[i - 1][1]);
  }
  for (int i = 0; i < N; i++) {
    add(o[i][1] + 1, o[i + o[i][0] - 1][1]);
    if (i + o[i][0] - 1 == (int)o.size() - 1) {
      o.push_back({-1, o[i][1] + 1});
    }
  }
  vector<int> used(2 * N + 1);
  for (int i = 1; i <= 2 * N; i++) {
    for (int j : ans[i]) {
      if (!used[j]) {
        cout << i << ' ' << j << '\n';
      }
    }
    used[i] = 1;
  }
}
