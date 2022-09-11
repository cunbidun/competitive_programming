#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, Q;
    cin >> N;
    vector<long long> tree_x(N), tree_y(N);
    for (int i = 0; i < N; i++) {
      cin >> tree_x[i] >> tree_y[i];
    }
    cin >> Q;
    vector<long long> well_x(Q), well_y(Q);
    for (int i = 0; i < Q; i++) {
      cin >> well_x[i] >> well_y[i];
    }
    sort(tree_x.begin(), tree_x.end());
    sort(well_x.begin(), well_x.end());
    sort(tree_y.begin(), tree_y.end());
    sort(well_y.begin(), well_y.end());

    auto compute = [&](vector<long long> &tree, vector<long long> &well) -> long long {
      long long total = 0;
      long long sum = 0;
      long long prod = 0;
      auto add_well = [&](long long num_tree, int p) -> void {
        if (num_tree != 0) {
          long long add = (((num_tree * well[p] - sum) % MOD) * ((num_tree * well[p] - sum) % MOD)) % MOD;
          long long number_of_pair = (1LL * num_tree * (num_tree - 1) / 2) % MOD;
          long long sub1 = (number_of_pair * ((well[p] * well[p]) % MOD)) % MOD;
          long long sub2 = (((num_tree - 1) * well[p]) % MOD * sum) % MOD;
          long long sub = (2 * ((sub1 - sub2 + prod) % MOD + MOD) % MOD) % MOD;

          if (num_tree == 1) {
            total = (total + add) % MOD;
          } else {
            total = ((total + add - sub) % MOD + MOD) % MOD;
          }
        }
      };
      int p = 0;
      for (int i = 0; i < N; i++) {
        while (p < Q && well[p] < tree[i]) {
          add_well(i, p);
          p++;
        }
        if (p == Q) {
          break;
        }
        prod = (prod + 1LL * tree[i] * sum) % MOD;
        sum = (sum + tree[i]) % MOD;
      }
      while (p < Q) {
        add_well(N, p);
        p++;
      }
      return total;
    };

    long long ans = 0;
    ans += compute(tree_x, well_x);
    ans += compute(tree_y, well_y);

    reverse(tree_x.begin(), tree_x.end());
    reverse(well_x.begin(), well_x.end());
    reverse(tree_y.begin(), tree_y.end());
    reverse(well_y.begin(), well_y.end());
    for (int i = 0; i < N; i++) {
      tree_x[i] = 1e9 + 5 - tree_x[i];
    }
    for (int i = 0; i < Q; i++) {
      well_x[i] = 1e9 + 5 - well_x[i];
    }
    for (int i = 0; i < N; i++) {
      tree_y[i] = 1e9 + 5 - tree_y[i];
    }
    for (int i = 0; i < Q; i++) {
      well_y[i] = 1e9 + 5 - well_y[i];
    }
    ans += compute(tree_x, well_x);
    ans += compute(tree_y, well_y);
    cout << ans % MOD << '\n';
  }
}
