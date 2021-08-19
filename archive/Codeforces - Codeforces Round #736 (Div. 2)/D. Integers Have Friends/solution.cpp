#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T &, const T &)>>
class sparse_table {
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
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    if (N == 1) {
      cout << N << '\n';
      continue;
    }
    for (int i = 1; i < N; i++) {
      a[i - 1] = abs(a[i - 1] - a[i]);
    }
    a.resize(N - 1);
    sparse_table<long long> st(a, [](long long i, long long j) { return __gcd(i, j); });
    int p = 0;
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
      while (p <= i && st.get(p, i) == 1) {
        p++;
      }
      ans = max(ans, i - p + 1);
    }
    cout << ans + 1 << '\n';
  }
}
