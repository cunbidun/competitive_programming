/**
 *  author: cunbidun
 *  created: Tuesday, 2023-08-29 20:31:08 CDT
 **/
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<vector<array<int, 2>>> tree(N + 1);
  for (int i = 1; i <= N - 1; i++) {
    int u, v;
    cin >> u >> v;
    tree[v].push_back({u, i});
    tree[u].push_back({v, i});
  }
  map<int, int> count;
  int mx = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    count[a[i]]++;
    if (count[a[i]] >= 2) {
      mx = max(mx, a[i]);
    }
  }
  vector<int> ans(N, mx);
  if (mx == 0 || count[mx] > 2) {
    for (int i = 1; i <= N - 1; i++) {
      cout << ans[i] << '\n';
    }
    return 0;
  }

  vector<int> ends;
  for (int i = 1; i <= N; i++) {
    if (a[i] == mx) {
      ends.push_back(i);
    }
  }

  vector<array<int, 2>> p(N + 1);
  p[ends[0]] = {ends[0], 0};

  yc([&](auto dfs, int u, int l) -> void {
    for (auto [v, idx] : tree[u]) {
      if (v != l) {
        p[v] = {u, idx};
        dfs(v, u);
      }
    }
  })(ends[0], ends[0]);

  // cout << ends[0] << ' ' << ends[1] << '\n';
  vector<array<int, 2>> path;
  int current = ends[1];
  while (current != ends[0]) {
    path.push_back({current, p[current][1]});
    current = p[current][0];
  }
  path.push_back({ends[0], 0});
  // debug() << imie(path);

  count.clear();
  mx = 0;

  auto add = yc([&](auto dfs, int u, int l1, int l2) -> void {
    count[a[u]]++;
    if (count[a[u]] >= 2) {
      mx = max(mx, a[u]);
    }
    for (auto [v, idx] : tree[u]) {
      if (v != l1 && v != l2) {
        dfs(v, u, u);
      }
    }
  });
  vector<int> store_0(N + 1), store_1(N + 1);

  for (int i = 0; i < (int)path.size() - 1; i++) {
    int b = path[i + 1][0];
    if (i != 0) {
      b = path[i - 1][0];
    }
    add(path[i][0], path[i + 1][0], b);
    store_0[path[i][0]] = mx;
  }
  count.clear();
  mx = 0;
  reverse(path.begin(), path.end());

  for (int i = 0; i < (int)path.size() - 1; i++) {
    int b = path[i + 1][0];
    if (i != 0) {
      b = path[i - 1][0];
    }
    add(path[i][0], path[i + 1][0], b);
    store_1[path[i][0]] = mx;
  }

  current = ends[1];
  while (current != ends[0]) {
    ans[p[current][1]] = max(store_0[current], store_1[p[current][0]]);
    current = p[current][0];
  }
  for (int i = 1; i < N; i++) {
    cout << ans[i] << '\n';
  }
}
