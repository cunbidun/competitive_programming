#include <bits/stdc++.h>

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

struct union_find {
  typedef vector<int> vi;
  vi p, sz, rank;
  int dsu_size;
  union_find(int _n) : p(vi(_n)), sz(vi(_n, 1)), rank(vi(_n)), dsu_size(_n) {
    for (int i = 0; i < _n; i++) {
      p[i] = i;
    }
  }
  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
  bool is_same_set(int x, int y) { return find(x) == find(y); }
  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x), y = find(y);
      if (rank[x] > rank[y]) {
        p[y] = x, sz[x] += sz[y];
      } else {
        p[x] = y, sz[y] += sz[x];
        rank[y] += (rank[x] == rank[y]);
      }
    }
  }
  int size(int i) { return sz[find(i)]; }
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
    int tot = 0;
    vector<int> odd;
    for (int i = 0; i < N; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
      tot += a[i];
      if (a[i] == 1) {
        odd.push_back(i);
      }
    }
    if (tot % 2 != 0 || tot == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    union_find dsu(N);
    vector<set<int>> tree(N);
    auto add_edge = [&tree](int i, int j) {
      tree[i].insert(j);
      tree[j].insert(i);
    };
    auto remove_edge = [&tree](int i, int j) {
      tree[i].erase(j);
      tree[j].erase(i);
    };
    int cur_sum = 1;
    for (int j = odd.back() + 1;; j++) {
      int i = j % N;
      if (i == odd.back()) {
        break;
      }
      int last = (i - 1 + N) % N;
      if (cur_sum % 2 == 1) {
        add_edge(i, last);
        dsu.merge(i, last);
      }
      cur_sum += a[i];
    }
    for (int i = 1; i < N; i++) {
      if (!dsu.is_same_set(0, i)) {
        dsu.merge(i, i - 1);
        int mx = *tree[i - 1].rbegin();
        int mn = *tree[i - 1].begin();
        int last = mx;
        if (mx < i) {
          last = mn;
        }
        remove_edge(last, i - 1);
        add_edge(i - 1, i);
        add_edge(i, last);
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j : tree[i]) {
        if (i < j) {
          cout << i + 1 << ' ' << j + 1 << '\n';
        }
      }
    }
  }
}
