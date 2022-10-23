#include <array>
#include <functional>
#include <iostream>
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
  int T;
  cin >> T;
  while (T--) {
    int N;
    long long K;
    cin >> N >> K;
    vector<vector<int>> a(N + 1);
    vector<long long> s(N + 1);
    for (int i = 2; i <= N; i++) {
      int p;
      cin >> p;
      a[p].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
      cin >> s[i];
    }

    auto solve = yc([&](auto _dfs, int u, long long num) -> array<long long, 2> {
      if (a[u].empty()) {
        return {num * s[u], s[u]};
      }
      int sz = a[u].size();
      long long cur_mx = 0;
      vector<long long> next_list;
      for (int v : a[u]) {
        auto [v_mx, v_next] = _dfs(v, num / sz);
        next_list.push_back(v_next);
        if (num / sz > 0) {
          cur_mx += s[u] * (num / sz) + v_mx;
        }
      }
      sort(next_list.begin(), next_list.end());
      reverse(next_list.begin(), next_list.end());
      for (int i = 0; i < num % sz; i++) {
        cur_mx += s[u] + next_list[i];
      }
      long long next_value = s[u] + next_list[num % sz];
      return {cur_mx, next_value};
    });

    auto [ans, _] = solve(1, K);
    cout << ans << '\n';
  }
}
