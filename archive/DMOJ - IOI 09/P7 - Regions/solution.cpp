#include <bits/stdc++.h>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
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
  int N, R, Q;
  cin >> N >> R >> Q;
  const int C = sqrt(N);
  vector<vector<array<int, 2>>> rlist(R + 1);
  vector<vector<int>> a(N + 1);
  vector<int> region(N + 1);
  vector<int> newr(N + 1);
  cin >> region[1];
  for (int i = 2; i <= N; i++) {
    int p;
    cin >> p >> region[i];
    a[p].push_back(i);
  }
  int cnt = 0;
  yc([&](auto dfs, int u, int l = 1) -> void {
    int s = ++cnt;
    newr[cnt] = region[u];
    for (int v : a[u]) {
      if (v != l) {
        dfs(v, u);
      }
    }
    int e = cnt;
    rlist[region[u]].push_back({s, e});
  })(1);
  auto rrlist = rlist;
  for (int i = 1; i <= R; i++) {
    sort(rlist[i].begin(), rlist[i].end());
  }
  vector<vector<int>> cache1(R + 1);
  vector<vector<int>> cache2(R + 1);
  for (int i = 1; i <= R; i++) {
    if ((int)rlist[i].size() >= C) {
      cache1[i].assign(R + 1, 0);
      cache2[i].assign(R + 1, 0);
      vector<int> tmp(N + 2);
      for (auto [s, e] : rlist[i]) {
        tmp[s]++;
        tmp[e + 1]--;
      }
      int cur = 0;
      for (int j = 1; j <= N; j++) {
        cur += tmp[j];
        cache1[i][newr[j]] += cur;
      }
      tmp.assign(N + 1, 0);
      cur = 0;
      for (auto [s, e] : rlist[i]) {
        tmp[s]++;
      }
      for (int j = 1; j <= N; j++) {
        tmp[j] += tmp[j - 1];
      }
      for (int j = 1; j <= R; j++) {
        if (i != j) {
          for (auto [s, e] : rlist[j]) {
            cache2[i][j] += tmp[e] - tmp[s - 1];
          }
        }
      }
    }
  }
  while (Q--) {
    int r1, r2;
    cin >> r1 >> r2;
    if ((int)rlist[r1].size() >= C || (int)rlist[r2].size() >= C) {
      if ((int)rlist[r1].size() >= C) {
        cout << cache1[r1][r2] << endl;
      } else {
        cout << cache2[r2][r1] << endl;
      }
    } else {
      int ans = 0;
      vector<int> tmp(rlist[r1].size());
      cnt = 0;
      for (int i = 0; i < (int)rlist[r1].size(); i++) {
        while (cnt < (int)rlist[r2].size() &&
               rlist[r2][cnt][0] < rlist[r1][i][0]) {
          cnt++;
        }
        tmp[i] = cnt;
      }
      cnt = 0;
      for (int i = 0; i < (int)rrlist[r1].size(); i++) {
        while (cnt < (int)rlist[r2].size() &&
               rlist[r2][cnt][0] <= rrlist[r1][i][1]) {
          cnt++;
        }
        ans += cnt - tmp[i];
      }
      cout << ans << endl;
    }
  }
}
