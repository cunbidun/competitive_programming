#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  int MX = 2e5 + 4;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  while (cin >> N) {
    if (N == 0) {
      break;
    }
    int M;
    cin >> M;
    vector<int> a(N);
    vector<int> cnt(MX), l(MX, MX), r(MX, -1), arr, pos(MX);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      a[i] += 100000;
      cnt[a[i]]++;
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    for (int i = 0; i < N; i++) {
      if (i == 0 || a[i] != a[i - 1]) {
        arr.push_back(cnt[a[i]]);
        pos[a[i]] = arr.size() - 1;
      }
    }
    vector<vector<int>> st(N, vector<int>(20));
    for (int i = 0; i < (int)arr.size(); i++) {
      st[i][0] = arr[i];
    }
    for (int j = 1; j <= 18; j++) {
      for (int i = 0; i + (1 << (j - 1)) < N; i++) {
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
    auto rmq = [&st](int l, int r) -> int {
      int k = log2(r - l + 1);
      return max(st[l][k], st[r - (1 << k) + 1][k]);
    };

    while (M--) {
      int s, e;
      cin >> s >> e;
      s--, e--;
      if (a[s] == a[e]) {
        cout << e - s + 1 << '\n';
        continue;
      }
      int sval = r[a[s]] - s + 1;
      int eval = e - l[a[e]] + 1;

      int nxt_pos = r[a[s]] + 1;
      int pre_pos = l[a[e]] - 1;
      if (nxt_pos > pre_pos) {
        cout << max(sval, eval) << '\n';
      } else {
        cout << max(max(sval, eval), rmq(pos[a[nxt_pos]], pos[a[pre_pos]])) << '\n';
      }
    }
  }
}
