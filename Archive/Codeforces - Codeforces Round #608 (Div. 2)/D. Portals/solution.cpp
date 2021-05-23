#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<array<int, 4>> a(N);
  vector<int> p(N), remain(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    a[i][3] = i;
    p[i] = i;
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    p[v] = max(p[v], u);
  }
  int cur = K;
  if (cur < a[0][0]) {
    cout << -1 << '\n';
    return 0;
  }
  auto check = [&](int tmp, int i) -> int {
    int ok = 1;
    for (int j = i; j < N; j++) {
      if (tmp < a[j][0]) {
        ok = 0;
        break;
      }
      tmp += a[j][1];
    }
    return ok;
  };
  for (int i = 0; i < N - 1; i++) {
    cur += a[i][1];
    int l = 0, r = cur;
    if (!check(cur, i + 1)) {
      cout << -1 << '\n';
      return 0;
    }
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (check(cur - m, i + 1)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    remain[i] = l;
    cur -= l;
  }
  cur = K;
  for (int i = 0; i < N - 1; i++) {
    cur += a[i][1];
    cur -= remain[i];
  }
  cur += a[N - 1][1];
  remain[N - 1] = cur;
  vector<int> r;
  for (int i = 0; i < N; i++) {
    while (remain[i] > 0) {
      r.push_back(i);
      remain[i]--;
    }
  }
  sort(a.begin(), a.end(), [](auto f, auto s) { return f[2] > s[2]; });
  int ans = 0;
  for (auto i : a) {
    auto it = upper_bound(r.begin(), r.end(), p[i[3]]);
    if (it == r.begin()) {
      continue;
    }
    it--;
    r.erase(it);
    ans += i[2];
  }
  cout << ans << '\n';
}
