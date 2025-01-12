#include <bits/stdc++.h>

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

struct TreeNode {
  int value;
  int left_size;
  int right_size;
  int size;
  struct TreeNode *left;
  struct TreeNode *right;
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
    vector<int> p(N + 1);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      p[a[i]] = i;
    }
    set<pair<int, int>> current_pos;
    current_pos.insert({-1, -1});
    current_pos.insert({N, -1});
    map<int, TreeNode *> nodes;
    long long total = 0;
    for (int i = 1; i <= N; i++) {
      int pos = p[i];
      auto right = current_pos.upper_bound({pos, i});
      auto left = prev(right);
      current_pos.insert({pos, i});
      auto node = new TreeNode({i,
                                pos - left->first - 1,
                                right->first - pos - 1,
                                pos - left->first - 1 + right->first - pos - 1 + 1,
                                nullptr,
                                nullptr});
      auto mn_value = max(left->second, right->second);
      if (mn_value != -1) {
        if (left->second == mn_value) {
          nodes[mn_value]->right = node;
        } else {
          nodes[mn_value]->left = node;
        }
      }
      nodes[i] = node;
      total += 1LL * i * (pos - left->first) * (right->first - pos);
    }
    auto solve = [&](TreeNode *node) -> long long {
      auto left = node->left;
      auto right = node->right;
      vector<TreeNode *> left_nodes;
      vector<TreeNode *> right_nodes;
      while (left) {
        left_nodes.push_back(left);
        left = left->right;
      }
      while (right) {
        right_nodes.push_back(right);
        right = right->left;
      }
      int l = 0;
      int r = 0;
      long long res = 0;
      while (l < (int)left_nodes.size() && r < (int)right_nodes.size()) {
        long long change = 0;
        if (left_nodes[l]->value < right_nodes[r]->value) {
          change += 1LL * left_nodes[l]->value * (left_nodes[l]->left_size + 1) *
                    (left_nodes[l]->right_size + right_nodes[r]->size + 1);
          change -= 1LL * left_nodes[l]->value * (left_nodes[l]->left_size + 1) * (left_nodes[l]->right_size + 1);
          l++;
        } else {
          change += 1LL * right_nodes[r]->value * (right_nodes[r]->right_size + 1) *
                    (right_nodes[r]->left_size + left_nodes[l]->size + 1);
          change -= 1LL * right_nodes[r]->value * (right_nodes[r]->left_size + 1) * (right_nodes[r]->right_size + 1);
          r++;
        }
        res += change;
      }
      return res;
    };
    vector<long long> ans(N);
    yc([&](auto dfs, TreeNode *node, long long from_parent) -> void {
      if (!node) {
        return;
      }
      long long from_children = solve(node);
      ans[p[node->value]] =
          total + from_children - 1LL * node->value * (node->left_size + 1) * (node->right_size + 1) - from_parent;
      dfs(node->left, from_parent + 1LL * node->value * (node->right_size + 1));
      dfs(node->right, from_parent + 1LL * node->value * (node->left_size + 1));
    })(nodes[1], 0);
    for (int i = 0; i < N; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
