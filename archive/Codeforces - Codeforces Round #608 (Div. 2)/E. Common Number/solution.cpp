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
}  // namespace std

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N, K;
  cin >> N >> K;
  auto len = [](long long x) {
    int cnt = 1;
    while (x > 1) {
      x /= 2;
      cnt++;
    }
    return cnt;
  };
  int ln = len(N);
  auto get = yc([&](auto get, long long m) -> long long {
    long long tot = (1LL << (ln - len(m))) - 1;
    if (m < (N >> (ln - len(m)))) {
      tot += 1LL << (ln - len(m));
    } else if (m == (N >> (ln - len(m)))) {
      tot += N - (m << (ln - len(m))) + 1;
    }
    if (m % 2 == 0) {
      return tot + get(m + 1);
    }
    return tot;
  });

  long long l = 0, r = N / 2;
  if (N % 2 == 0) {
    r--;
  }

  while (l < r) {
    long long m = (l + r + 1) / 2;
    if (get(m * 2 + 1) >= K) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  long long l0 = l;
  if (get(2) >= K) {
    l = 1, r = N / 2;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      if (get(m * 2) >= K) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    cout << max(l0 * 2 + 1, l * 2) << '\n';
  } else {
    cout << l0 * 2 + 1 << '\n';
  }
}
