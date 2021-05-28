#include <bits/stdc++.h>

using namespace std;

// fenwick_tree
// 1-based index
template <typename T>
struct fenwick_tree {
  vector<T> bit;
  int n;
  fenwick_tree() {}
  fenwick_tree(int _n) { init(_n); }
  void init(int _n) {
    n = _n;
    bit.assign(n + 1, 0);
  }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v;
      p += p & -p;
    }
  }
  T get(int p) {
    T res = 0;
    while (p >= 1) {
      res += bit[p];
      p -= p & -p;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 2>> a(N + 1);
  set<int> p;

  for (int i = 1; i <= N; i++) {
    cin >> a[i][0];
    a[i][1] = i;
    if (a[i][0] >= 0) {
      p.insert(i);
    }
  }
  fenwick_tree<long long> bit(N);
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i][0] >= 0) {
      bit.update(i, a[i][0]);
      ans++;
    }
  }

  vector<array<int, 2>> b = a;
  sort(a.begin() + 1, a.end(), [](auto A, auto B) {
    return A[0] > B[0];
  });
  int cur = (int)p.size() - 1;
  for (int i = 1; i <= N; i++) {
    if (a[i][0] < 0) {
      if (a[i][0] + bit.get(a[i][1]) >= 0) {
        ans++;
        // cout << a[i][1] << '\n';
        while (!p.empty()) {
          auto it = p.upper_bound(a[i][1]);
          it--;
          long long prev = b[*it][0];
          long long mn = min(1LL * abs(a[i][0]), prev);
          // cout << *it << ' ' << mn << '\n';
          b[*it][0] -= mn;
          bit.update(*it, -mn);
          a[i][0] += mn;
          if (prev == mn) {
            p.erase(it);
          }
          if (a[i][0] == 0) {
            break;
          }
        }
      }
    }
  }
  cout << ans << '\n';
}
