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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    set<int> s;
    int ok = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      a[i] = abs(a[i]);
      ok |= a[i] == 0;
    }
    vector<int> v(N);
    yc([&](auto bt, int p) -> void {
      if (p == N) {
        vector<int> cnt(3);
        for (int i = 0; i < p; i++) {
          cnt[v[i]] += a[i];
        }
        ok |= (cnt[0] != 0) && cnt[0] == cnt[1];
        return;
      }
      for (int i = 0; i < 3; i++) {
        v[p] = i;
        bt(p + 1);
      }
    })(0);
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
