/**
 *  author: cunbidun
 *  created: Saturday, 2023-09-23 16:15:37 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int M = 998244353;
  while (T--) {
    int N, s;
    cin >> N >> s;
    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
      cin >> b[i];
    }
    int f = 0;
    set<int> st;
    vector<int> ch(N + 1);
    vector<int> p;
    for (int i = 1; i <= N; i++) {
      if (b[i] != -1) {
        if (a[i] - b[i] > s) {
          f = 1;
        }
        ch[b[i]] = 1;
      } else {
        p.push_back(a[i]);
      }
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    vector<int> idx(N + 1);
    for (int i = 1; i <= N; i++) {
      if (!ch[i]) {
        idx[i] = st.size();
        st.insert(i);
      }
    }
    if (f == 1) {
      cout << 0 << '\n';
      continue;
    }
    int ans = 1;
    int cnt = 0;
    for (int e : p) {
      auto it = st.lower_bound(e - s);
      if (it == st.end()) {
        ans = 0;
      } else {
        auto num = *it;
        // cout << e << ' ' << num << ' ' << idx[num] << ' ' << st.size() - idx[num] - cnt << '\n';
        ans = (1LL * ans * (st.size() - idx[num] - cnt)) % M;
        cnt++;
      }
    }
    cout << ans << '\n';
  }
}
