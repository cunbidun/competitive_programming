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
    n = _n, bit.assign(n + 1, T{});
  }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v, p += p & -p;
    }
  }
  T get(int p) {
    T res{};
    while (p >= 1) {
      res += bit[p], p -= p & -p;
    }
    return res;
  }
  T get(int l, int r) { return (l > r) ? T{} : get(r) - get(l - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int MN = 3e5 + 5;
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> ch(MN);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  fenwick_tree<long long> bit, cnt;
  cnt.init(MN);
  bit.init(MN);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long resf = bit.get(1, a[i]);
    for (int j = a[i]; j <= MN; j += a[i]) {
      int up = min(j + a[i] - 1, MN);
      resf += bit.get(j, up) - cnt.get(j, up) * j;
    }
    long long resb = 1LL * a[i] * cnt.get(a[i], MN);
    int p = 1;
    for (int j = 2; j * j <= a[i]; j++) {
      int cur = a[i] / (j - 1);
      int next = a[i] / j + 1;
      resb += 1LL * a[i] * cnt.get(next, cur) - bit.get(next, cur) * (j - 1);
      p = j;
    }
    int upper = a[i] / p;
    for (int j = 1; j <= upper; j++) {
      if (ch[j] == 1) {
        resb += a[i] % j;
      }
    }
    ans += resf + resb;
    cout << ans << ' ';
    ch[a[i]] = 1;
    cnt.update(a[i], 1);
    bit.update(a[i], a[i]);
  }
  cout << '\n';
}
