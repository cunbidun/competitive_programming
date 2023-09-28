/**
 *  author: cunbidun
 *  created: Friday, 2023-09-08 23:48:49 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T> struct segment_tree {
  int n;
  vector<T> st, lazy;
  segment_tree(int _n) : n(_n) { st.assign(4 * n, numeric_limits<T>::min()); }
  void update(int i, int l, int r, int p, T v) {
    if (r < p || p < l) {
      return;
    }
    if (p == l && r == p) {
      st[i] = v;
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, p, v);
    update(i * 2 + 2, m + 1, r, p, v);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }
  T get_max(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return numeric_limits<T>::min();
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, ql, qr), get_max(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int p, T v) { update(0, 0, n - 1, p, v); }
  T get_max(int L, int R) { return get_max(0, 0, n - 1, L, R); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> s(N + 1);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    s[i] = s[i - 1] + x;
  }
  vector<long long> tmp = s;
  sort(tmp.begin(), tmp.end());
  map<long long, int> mp;
  for (int i = 0; i <= N; i++) {
    if (!mp.count(tmp[i])) {
      mp[tmp[i]] = mp.size();
    }
  }
  segment_tree<long long> st(N + 1);
  vector<long long> f(N + 1);
  long long ans = 0;
  st.update(mp[0], 0);
  for (int i = 1; i <= N; i++) {
    int current_index = mp[s[i]];
    long long current_mx = st.get_max(0, current_index);
    f[i] = max(f[i - 1], current_mx + i);
    st.update(current_index, f[i] - i);
    ans = max(ans, f[i]);
  }
  cout << ans << '\n';
}
