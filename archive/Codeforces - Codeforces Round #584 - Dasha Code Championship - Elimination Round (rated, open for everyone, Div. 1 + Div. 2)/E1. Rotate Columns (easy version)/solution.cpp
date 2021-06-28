#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> a;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int x;
        cin >> x;
        a.push_back({x, j, i});
      }
    }
    sort(a.begin(), a.end(), [](auto f, auto s) {
      return f[0] > s[0];
    });
    auto cal = [&](vector<int> tmp) -> int {
      set<int> s;
      for (int i : tmp) {
        s.insert(a[i][1]);
      }
      if (s.size() != 2) {
        return a[tmp[0]][0] + a[tmp[1]][0] + a[tmp[2]][0] + a[tmp[3]][0];
      }
      bool ok = 0;
      do {
        ok |= (a[tmp[0]][1] == a[tmp[1]][1]) && (a[tmp[0]][1] == a[tmp[2]][1]);
        if ((a[tmp[0]][1] == a[tmp[1]][1]) && (a[tmp[2]][1] == a[tmp[3]][1])) {
          ok |= ((abs(a[tmp[0]][2] - a[tmp[1]][2]) - abs(a[tmp[2]][2] - a[tmp[3]][2])) % 2 == 0);
        }
      } while (next_permutation(tmp.begin(), tmp.end()));
      if (!ok) {
        return -1;
      }
      return a[tmp[0]][0] + a[tmp[1]][0] + a[tmp[2]][0] + a[tmp[3]][0];
    };
    int ans = 0;
    if (N < 4 || M == 1) {
      for (int i = 0; i < N; i++) {
        ans += a[i][0];
      }
      cout << ans << '\n';
      continue;
    }
    ans = max(ans, cal({0, 1, 2, 3}));
    ans = max(ans, cal({0, 1, 2, 4}));
    ans = max(ans, cal({0, 1, 2, 5}));
    ans = max(ans, cal({0, 1, 3, 4}));
    cout << ans << '\n';
  }
}
