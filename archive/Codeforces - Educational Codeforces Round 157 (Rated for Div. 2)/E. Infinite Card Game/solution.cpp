#include <bits/stdc++.h>

using namespace std;

template <class c> struct rge {
  c b, e;
};
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<array<int, 3>> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i][0];
      a[i][2] = i;
    }
    for (int i = 0; i < N; i++) {
      cin >> a[i][1];
    }
    int M;
    cin >> M;
    vector<array<int, 3>> b(M);
    for (int i = 0; i < M; i++) {
      cin >> b[i][0];
      b[i][2] = i;
    }
    for (int i = 0; i < M; i++) {
      cin >> b[i][1];
    }

    auto optimal_responses = [&](vector<array<int, 3>> f, vector<array<int, 3>> s) -> vector<int> {
      // for each element in b, find the most optimal response in a

      sort(f.begin(), f.end());
      // debug() << imie(f);
      int n = (int)f.size();
      vector<array<int, 2>> max_suffix(n);
      max_suffix[n - 1] = {f[n - 1][1], f[n - 1][2]};
      for (int i = n - 2; i >= 0; i--) {
        if (f[i][1] > max_suffix[i + 1][0]) {
          max_suffix[i] = {f[i][1], f[i][2]};
        } else {
          max_suffix[i] = max_suffix[i + 1];
        }
      }
      vector<int> best_responses(s.size(), -1);
      for (auto [sa, sd, id] : s) {
        int l = 0, r = n - 1;
        while (l < r) {
          int m = (l + r) / 2;
          if (f[m][0] > sd) {
            r = m;
          } else {
            l = m + 1;
          }
        }
        if (f[l][0] > sd) {
          best_responses[id] = max_suffix[l][1];
        }
      }
      return best_responses;
    };
    auto best_responses_to_a = optimal_responses(b, a);
    auto best_responses_to_b = optimal_responses(a, b);
    // debug() << imie(best_responses_to_a);
    // debug() << imie(best_responses_to_b);

    vector<int> v(N + M);
    vector<int> t(N + M);
    auto dfs = yc([&](auto _dfs, int u) -> void {
      v[u] = 1;
      int nxt = -1;
      if (u < N) {
        nxt = best_responses_to_a[u];
        if (nxt == -1) {
          t[u] = 1;
        } else {
          nxt += N;
        }

      } else {
        nxt = best_responses_to_b[u - N];
        if (nxt == -1) {
          t[u] = -1;
        }
      }
      // cout << u << ' ' << nxt << '\n';
      if (nxt == -1) {
        return;
      }
      if (!v[nxt]) {
        _dfs(nxt);
      }
      t[u] = t[nxt];
    });
    int w = 0, d = 0, l = 0;
    for (int i = 0; i < N; i++) {
      dfs(i);
      if (t[i] == 0) {
        d++;
      } else if (t[i] == 1) {
        w++;
      } else {
        l++;
      }
    }
    cout << w << ' ' << d << ' ' << l << '\n';
  }
}
