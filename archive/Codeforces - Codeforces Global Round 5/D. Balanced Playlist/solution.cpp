#include <bits/stdc++.h>
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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(3 * N);
  vector<vector<int>> st(3 * N, vector<int>(20));
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i + N] = a[i];
    a[i + 2 * N] = a[i];
  }
  N = (int)a.size();
  for (int i = 0; i < N; i++) {
    st[i][0] = a[i];
  }
  for (int j = 1; j <= 18; j++) {
    for (int i = 0; i + (1 << (j - 1)) < N; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto rmq = yc([&](auto rmq, int l, int r) -> int {
    int k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
  });
  if (*min_element(a.begin(), a.end()) * 2 >= *max_element(a.begin(), a.end())) {
    for (int i = 0; i < N / 3; i++) {
      cout << -1 << ' ';
    }
    return 0;
  }
  int p = 1;
  for (int i = 0; i < N / 3; i++) {
    while ((rmq(i, p) + 1) / 2 <= a[p]) {
      p++;
    }
    cout << p - i << ' ';
  }
  cout << '\n';
}
