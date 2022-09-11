#include <array>
#include <functional>
#include <iostream>
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

int main() {
  int MX = 10000005;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> lp;
  vector<int> pr;
  auto sieve = [&lp, &pr](int N) {
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j) {
        lp[i * pr[j]] = pr[j];
      }
    }
  };
  sieve(MX);
  lp[1] = 1;

  int N;
  cin >> N;
  vector<int> a(N + 1), last_left(MX), last_right(MX, N + 1), left(N + 1), right(N + 2);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    int mx = -1;
    int x = a[i];
    while (lp[x] != 1) {
      int smallest = lp[x];
      mx = max(last_left[smallest], mx);
      while (x % smallest == 0) {
        x /= smallest;
      }
      last_left[smallest] = i;
    }
    left[i] = mx + 1;
  }

  for (int i = N; i >= 1; i--) {
    cin >> a[i];
    int mn = N + 1;
    int x = a[i];
    while (lp[x] != 1) {
      int smallest = lp[x];
      mn = min(last_right[smallest], mn);
      while (x % smallest == 0) {
        x /= smallest;
      }
      last_right[smallest] = i;
    }
    right[i] = mn - 1;
  }

  vector<int> parent(N + 1);

  int ans = yc([&](auto build_tree, int l, int r) -> int {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return l;
    }
    int root = -1;
    int cur_l = l, cur_r = r;
    while (cur_l <= cur_r) {
      if (left[cur_l] <= l && r <= right[cur_l]) {
        root = cur_l;
        break;
      } else if (left[cur_r] <= l && r <= right[cur_r]) {
        root = cur_r;
        break;
      }
      cur_l++;
      cur_r--;
    }
    if (root == -1) {
      return -1;
    }
    int left_root = build_tree(l, root - 1);
    int right_root = build_tree(root + 1, r);
    if (left_root == -1 || right_root == -1) {
      return -1;
    }
    parent[left_root] = root;
    parent[right_root] = root;
    return root;
  })(1, N);

  if (ans == -1) {
    cout << "impossible\n";
    return 0;
  }
  for (int i = 1; i <= N; i++) {
    cout << parent[i] << ' ';
  }
  cout << '\n';
}
