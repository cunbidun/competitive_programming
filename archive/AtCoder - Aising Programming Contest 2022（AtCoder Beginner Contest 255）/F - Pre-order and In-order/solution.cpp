#include <bits/stdc++.h>
#include <vector>

using namespace std;

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

template <typename T, class F = function<T(const T &, const T &)>> class SparseTable {
public:
  int N;
  vector<vector<T>> st;
  F func;
  SparseTable(const vector<T> &a, const F &f = F{}) : func(f) {
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

template <typename T> struct MinPos {
  T val;   // the element value
  int idx; // its index in the input array
};
template <typename T> struct MinPosOp {
  constexpr MinPos<T> operator()(const MinPos<T> &a, const MinPos<T> &b) const noexcept {
    if (a.val < b.val)
      return a; // strictly smaller
    if (b.val < a.val)
      return b;                     // strictly smaller
    return (a.idx < b.idx ? a : b); // tie‑break by left‑most index
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> P(N + 1);
  vector<int> I(N + 1);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    P[x] = i;
  };
  vector<MinPos<int>> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> I[i];
    A[i] = {P[I[i]], i};
  };
  SparseTable<MinPos<int>, MinPosOp<int>> st(A);
  vector<vector<int>> tree(N + 1);
  int root = 0;
  auto solve = yc([&](auto _solve, int l, int r) -> int {
    if (l > r) {
      return 0;
    }
    MinPos<int> m = st.get(l, r);
    int left = _solve(l, m.idx - 1);
    int right = _solve(m.idx + 1, r);
    int current_value = I[m.idx];
    if (l == 1 && r == N) {
      root = current_value;
    }
    tree[current_value].push_back(left);
    tree[current_value].push_back(right);
    return current_value;
  });
  solve(1, N);
  if (root != 1) {
    cout << -1 << '\n';
    return 0;
  }
  // compute pre-order traversal from root, and see if it's similar to vector I
  vector<int> pre_order;
  auto in_order_traversal = yc([&](auto _in_order_traversal, int node) -> void {
    if (node == 0) {
      return;
    }
    pre_order.push_back(node);
    _in_order_traversal(tree[node][0]);
    _in_order_traversal(tree[node][1]);
  });
  in_order_traversal(root);
  if ((int)pre_order.size() != N) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (pre_order[P[i + 1] - 1] != i + 1) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < (int)tree[i].size(); j++) {
      cout << tree[i][j] << ' ';
    }
    cout << '\n';
  }
}
