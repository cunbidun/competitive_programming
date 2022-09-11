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

// base 0
struct max_except {
  int n;
  vector<int> l, r;
  max_except(vector<int> &a) {
    n = a.size();
    l.assign(n + 2, -1e9);
    r.assign(n + 2, -1e9);
    for (int i = 0; i < n; i++) {
      l[i + 1] = max(l[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      r[i + 1] = max(r[i + 2], a[i]);
    }
  }
  int get(int p) {
    p += 1;
    return max(l[p - 1], r[p + 1]);
  }
};

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
    vector<int> c0, c1;
    for (int v : a[u]) {
      if (v != l) {
        auto res = dfs(v, u);
        c0.push_back(res[0]);
        c1.push_back(res[1]);
      }
    }

    int nc = c0.size();

    if (val[u] > 2) {
      return array<int, 2>{0, 0};
    }
    if (nc == 0) {
      if (val[u] == 2) {
        ans1 = max(ans1, 1);
        return array<int, 2>{0, 1};
      } else {
        ans0 = max(ans0, 1);
        return array<int, 2>{1, 0};
      }
    }
    if (nc == 1) {
      if (val[u] == 2) {
        ans1 = max(ans1, 1 + c0[0]);
        return array<int, 2>{0, 1 + c0[0]};
      } else {
        ans0 = max(ans0, 1 + c0[0]);
        ans1 = max(ans1, ((c1[0] == 0) ? 0 : 1 + c1[0]));
        return array<int, 2>{1 + c0[0], ((c1[0] == 0) ? 0 : 1 + c1[0])};
      }
    }
    max_except m0(c0), m1(c1);
    int mx0 = 0, mx1 = 0;
    for (int i = 0; i < nc; i++) {
      if (c0[i] > 0) {
        mx1 = max(mx1, c0[i] + m1.get(i));
      }
      if (c1[i] > 0) {
        mx1 = max(mx1, c1[i] + m0.get(i));
      }
    }
    sort(c0.begin(), c0.end(), greater<>());
    sort(c1.begin(), c1.end(), greater<>());
    mx0 = c0[0] + c0[1];
    mx1 = max(mx1, c1[0]);
    if (val[u] == 1) {
      ans0 = max(ans0, 1 + mx0);
      ans1 = max(ans1, 1 + mx1);
      return array<int, 2>{1 + c0[0], ((c1[0] == 0) ? 0 : 1 + c1[0])};
    } else {
      ans1 = max(ans1, 1 + mx0);
      return array<int, 2>{0, 1 + c0[0]};
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
