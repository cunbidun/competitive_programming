#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T &, const T &)>> class sparse_table {
public:
  int N;
  vector<vector<T>> st;
  F func;
  sparse_table(const vector<T> &a, const F &f) : func(f) {
    N = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(N);
    st.resize(N, vector<T>(max_log));
    for (int i = 0; i < N; i++) {
      st[i][0] = a[i];
    }
    for (int j = 1; j < max_log; j++) {
      for (int i = 0; i + (1 << (j - 1)) < N; i++) {
        st[i][j] = func(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T get(int l, int r) const {
    assert(0 <= l && l <= r && r <= N - 1);
    int k = log2(r - l + 1);
    return func(st[l][k], st[r - (1 << k) + 1][k]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> diff(N);

    auto compute_prime_dis = [](int d) -> int {
      while (d % 2 == 0 && d > 0) {
        d /= 2;
      }
      return d;
    };
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (i > 0) {
        diff[i] = compute_prime_dis(abs(a[i] - a[i - 1]));
      }
    }
    sparse_table<int> st(diff, [](int x1, int x2) -> int { return gcd(x1, x2); });
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      int p = N;
      for (int j = i; j < N; j++) {
        if (a[j] != a[i]) {
          p = j;
          break;
        }
        cnt++;
      }
      ans += 1LL * cnt * (cnt + 1) / 2;
      i = p - 1;

      int l = i + 1, r = N - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (st.get(i + 1, m) == 1) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      if (l < N && i < l && st.get(i + 1, l) == 1) {
        // cout << i << ' ' << l << '\n';
        ans += (N - l) * cnt;
      }
    }
    cout << ans << '\n';
  }
}
