/**
 *  author: cunbidun
 *  created: Tuesday, 2023-01-10 22:18:31 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <stack>
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> a(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  vector<int> ans(N);
  // odd.size() >= even.size() >= other.size()
  stack<int> odd, even, other;
  for (int i = 1; i <= N; i++) {
    if (i % 3 == 0) {
      other.push(i);
    } else if (i % 3 == 1) {
      odd.push(i);
    } else {
      even.push(i);
    }
  }
  vector<int> odd_lvl, even_lvl;
  yc([&](auto _dfs, int u, int l, int lvl) -> void {
    if (lvl % 2 == 1) {
      odd_lvl.push_back(u);
    } else {
      even_lvl.push_back(u);
    }
    for (int v : a[u]) {
      if (v != l) {
        _dfs(v, u, lvl + 1);
      }
    }
  })(0, 0, 1);

  if (odd_lvl.size() > even_lvl.size()) {
    swap(odd_lvl, even_lvl);
  }
  if (odd_lvl.size() <= other.size()) {
    for (int i = 0; i < (int)odd_lvl.size(); i++) {
      ans[odd_lvl[i]] = other.top();
      other.pop();
    }
    for (int i = 0; i < (int)even_lvl.size(); i++) {
      int val = -1;
      if (!other.empty()) {
        val = other.top();
        other.pop();
      } else if (!odd.empty()) {
        val = odd.top();
        odd.pop();
      } else {
        val = even.top();
        even.pop();
      }
      ans[even_lvl[i]] = val;
    }
  } else {
    for (int i = 0; i < (int)odd_lvl.size(); i++) {
      int val = -1;
      if (!even.empty()) {
        val = even.top();
        even.pop();
      } else {
        val = other.top();
        other.pop();
      }
      ans[odd_lvl[i]] = val;
    }
    for (int i = 0; i < (int)even_lvl.size(); i++) {
      int val = -1;
      if (!odd.empty()) {
        val = odd.top();
        odd.pop();
      } else {
        val = other.top();
        other.pop();
      }
      ans[even_lvl[i]] = val;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << ' ';
  }
}
