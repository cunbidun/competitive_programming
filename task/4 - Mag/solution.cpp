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

template <typename T> struct fraction {
  T P, Q;

  fraction() : P(0), Q(1){};

  fraction(T _P, T _Q) : P(_P), Q(_Q) {
    assert(Q != 0);
    auto g = gcd(P, Q);
    P /= g;
    Q /= g;
  }
  bool operator==(const fraction &o) { return P == o.P && Q == o.Q; }
  bool operator<=(const fraction &o) { return P * o.Q <= Q * o.P; }
  bool operator<(const fraction &o) { return P * o.Q < Q * o.P; }
  bool operator>=(const fraction &o) { return P * o.Q >= Q * o.P; }
  bool operator>(const fraction &o) { return P * o.Q > Q * o.P; }
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
  vector<array<fraction<long long>, 50>> f(N);
  fraction<int> ans;
  int mn = 1e9;
  for (int i = 0; i < N; i++) {
    cin >> val[i];
    mn = min(mn, val[i]);
  }
  ans = fraction(mn, 1);
  if (mn > 1) {
    cout << ans.P << '/' << ans.Q << '\n';
    return 0;
  }

  yc([&](auto dfs, int u, int l) -> array<fraction<int>, 20> {
    vector<array<fraction<int>, 20>> from_children;
    for (int v : a[u]) {
      if (v != l) {
        from_children.push_back(dfs(v, u));
      }
    }
  })(0, 0);
}
