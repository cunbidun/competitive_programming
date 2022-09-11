#include <array>
#include <functional>
#include <iostream>
#include <numeric>
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
  vector<vector<int>> a(N);
  vector<int> val(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int mn = 1e9;
  for (int i = 0; i < N; i++) {
    cin >> val[i];
    mn = min(mn, val[i]);
  }
  if (mn > 1) {
    cout << mn << '/' << 1 << '\n';
    return 0;
  }
  int ans0 = 0, ans1 = 0;

  yc([&](auto dfs, int u, int l) -> array<int, 2> {
    int mx01 = 0, mx02 = 0;
    int mx11 = 0, mx12 = 0;
    int p0 = 0, p1 = 0;
    int cnt = 0;
    for (int v : a[u]) {
      if (v != l) {
        auto res = dfs(v, u);
        if (res[0] > mx01) {
          mx02 = mx01;
          mx01 = res[0];
          p0 = cnt;
        } else {
          mx02 = max(res[0], mx02);
        }
        if (res[1] > mx11) {
          mx12 = mx11;
          mx11 = res[1];
          p1 = cnt;
        } else {
          mx12 = max(res[1], mx12);
        }
        ++cnt;
      }
    }
    if (val[u] > 2) {
      return {0, 0};
    }
    int mx0 = 0, mx1 = 0;
    mx0 = mx01 + mx02;
    if (p0 != p1) {
      if (mx11 > 0) {
        mx1 = mx01 + mx11;
      }
    } else {
      if (mx11 > 0) {
        mx1 = max(mx1, mx11 + mx02);
      }
      if (mx12 > 0) {
        mx1 = max(mx1, mx01 + mx12);
      }
    }
    if (val[u] == 1) {
      ans0 = max(ans0, 1 + mx0);
      if (mx1 > 0) {
        ans1 = max(ans1, 1 + mx1);
      }
      return {1 + mx01, ((mx11 == 0) ? 0 : 1 + mx11)};
    } else {
      ans1 = max(ans1, 1 + mx0);
      return {0, 1 + mx01};
    }
  })(0, 0);
  int ans = 0;
  if (ans0 * 2 < ans1) {
    ans = ans1;
  } else {
    ans = 2 * ans0;
  }
  cout << 2 / gcd(2, ans) << '/' << ans / gcd(2, ans) << '\n';
}
