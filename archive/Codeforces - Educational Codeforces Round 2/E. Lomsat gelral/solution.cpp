#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

namespace std {
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
} // namespace std

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<map<int, int>> t(N + 1);
  vector<int> sz(N + 1), mx(N + 1);
  vector<long long> sum(N + 1);
  for (int i = 1; i <= N; i++) {
    int c;
    cin >> c;
    t[i][c] = 1;
    sz[i] = 1;
    mx[i] = 1;
    sum[i] = c;
  }
  vector<vector<int>> a(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  auto merge = [&](int i, int j) {
    sz[j] += sz[i];
    for (auto [k, v] : t[i]) {
      int cur = t[j][k] + v;
      if (cur > mx[j]) {
        mx[j] = cur;
        sum[j] = k;
      } else if (cur == mx[j]) {
        sum[j] += k;
      }
      t[j][k] = cur;
    }
  };

  vector<long long> ans(N + 1);
  yc([&](auto dfs, int u, int l) -> void {
    vector<int> list;
    list.push_back(u);
    for (int v : a[u]) {
      if (v != l) {
        dfs(v, u);
        list.push_back(v);
      }
    }
    int last = list[0];
    for (int i = 1; i < (int)list.size(); i++) {
      if (sz[list[i]] < sz[last]) {
        merge(list[i], last);
      } else {
        merge(last, list[i]);
        last = list[i];
      }
    }
    swap(t[u], t[last]);
    sz[u] = sz[last];
    mx[u] = mx[last];
    sum[u] = sum[last];
    ans[u] = sum[u];
  })(1, 1);
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
