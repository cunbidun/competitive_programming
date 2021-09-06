#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  int sa = 0, sb = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sa += a[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> b[i];
    sb += b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  auto cal = [](vector<int> &cnt, int tar, int c) {
    if (c == tar) {
      return 0;
    }
    int res = 0;
    if (c < tar) {
      int cur = c;
      for (int j = 0; cur < tar && j < (int)cnt.size(); j++) {
        cur += 6 - cnt[j];
        res++;
      }
      if (cur < tar) {
        res += 1e9;
      }
    } else {
      int cur = c;
      for (int j = cnt.size() - 1; cur > tar && j >= 0; j--) {
        cur -= cnt[j] - 1;
        res ++;
      }
      if (cur > tar) {
        res += 1e9;
      }
    }
    return res;
  };
  int ans = 1e9;
  for (int i = 1; i <= 6000; i++) {
    ans = min(ans, cal(a, i, sa) + cal(b, i, sb));
  }
  if (ans >= 1e9) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
