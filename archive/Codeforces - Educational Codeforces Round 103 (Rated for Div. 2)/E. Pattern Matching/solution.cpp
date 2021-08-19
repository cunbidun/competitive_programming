#include <bits/stdc++.h>

using namespace std;

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun>
decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<string> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<vector<string>> list(N + 1);
  vector<pair<string, int>> str(M + 1);
  map<string, array<int, 2>> mp;
  for (int i = 1; i <= M; i++) {
    cin >> str[i].first >> str[i].second;
    auto it = mp.find(str[i].first);
    if (it != mp.end()) {
      if (it->second[0] != str[i].second) {
        cout << "NO\n";
        return 0;
      }
      str[i].first = "";
    } else {
      mp[str[i].first] = {str[i].second, i};
    }
  }

  vector<vector<int>> l(M + 1);
  for (int i = 1; i <= N; i++) {
    yc([&](auto build, string s, int c) -> void {
      if (c == K) {
        auto it = mp.find(s);
        if (it != mp.end()) {
          l[it->second[1]].push_back(i);
        }
        return;
      }
      if (a[i][c] != '_') {
        build(s + a[i][c], c + 1);
      } else {
        for (int j = 0; j < 26; j++) {
          build(s + (char)(j + 'a'), c + 1);
        }
      }
    })("", 0);
  }

  vector<vector<int>> g(N + 1);
  for (int i = 1; i <= M; i++) {
    if (str[i].first != "") {
      int ok = 0;
      for (int j : l[i]) {
        ok |= str[i].second == j;
        if (j != str[i].second) {
          g[str[i].second].push_back(j);
        }
      }
      if (!ok) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  vector<int> visited(N + 1);
  int f = 0;
  vector<int> order;
  auto dfs = yc([&](auto _dfs, int u) -> void {
    visited[u] = 1;
    for (int v : g[u]) {
      f |= visited[v] == 1;
      if (!visited[v]) {
        _dfs(v);
      }
    }
    visited[u] = 2;
    order.push_back(u);
  });
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  if (f) {
    cout << "NO\n";
    return 0;
  }
  reverse(order.begin(), order.end());

  cout << "YES\n";
  for (int i : order) {
    cout << i << ' ';
  }
  cout << '\n';
}
