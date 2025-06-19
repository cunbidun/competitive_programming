#include <bits/stdc++.h>
using namespace std;

template <class M> // M must provide: using value_type;
struct Fenwick {
  using T = typename M::value_type;
  int n;
  std::vector<T> bit;
  Fenwick(int _n = 0) { init(_n); }
  void init(int _n) {
    n = _n;
    bit.assign(n + 1, M::id());
  }
  void update(int p, T v) {
    for (; p <= n; p += p & -p)
      bit[p] = M::op(bit[p], v);
  }
  T get(int p) const {
    T res = M::id();
    for (; p; p &= p - 1)
      res = M::op(res, bit[p]);
    return res;
  }
};
/* ------ ready‑made monoids ------ */
struct MaxVal {
  using value_type = int;
  static value_type op(value_type a, value_type b) { return std::max(a, b); }
  static constexpr value_type id() { return std::numeric_limits<int>::min(); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &x : A)
      cin >> x;

    /* ---- 1. coordinate compression ---- */
    vector<int> vals = A;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int K = (int)vals.size();
    vector<int> R(N);
    for (int i = 0; i < N; ++i)
      R[i] = int(lower_bound(vals.begin(), vals.end(), A[i]) - vals.begin()) + 1; // 1‑based

    /* ---- 2. LIS ending at i ---- */
    Fenwick<MaxVal> bitL(K);
    vector<int> left(N);
    for (int i = 0; i < N; ++i) {
      int best = bitL.get(R[i] - 1); // max over smaller values
      left[i] = best + 1;
      bitL.update(R[i], left[i]);
    }

    /* ---- 3. LIS starting at i (mirror indices) ---- */
    Fenwick<MaxVal> bitR(K);
    vector<int> right(N);
    for (int i = N - 1; i >= 0; --i) {
      int idxRev = K - R[i] + 1;       // reflect rank
      int best = bitR.get(idxRev - 1); // ranks > A[i]
      right[i] = best + 1;
      bitR.update(idxRev, right[i]);
    }

    /* ---- 4. locate the maximum left+right ---- */
    long long bestSum = -1;
    for (int i = 0; i < N; ++i) {
      long long cur = left[i] + right[i];
      if (cur > bestSum)
        bestSum = cur;
    }
    vector<int> bestIndices;
    for (int i = 0; i < N; i++) {
      if (left[i] + right[i] == bestSum) {
        bestIndices.push_back(i);
      }
    }
    cout << bestIndices.size() << '\n';
    for (int i : bestIndices) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
