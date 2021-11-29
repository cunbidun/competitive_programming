#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<long long, 2>> e;
  for (int i = 0; i < N; i++) {
    long long l, r;
    cin >> l >> r;
    e.push_back({l, 1});
    e.push_back({r + 1, -1});
  }
  sort(e.begin(), e.end());
  vector<long long> ans(N + 1);
  int cnt = 0;
  for (int i = 0; i < 2 * N; i++) {
    if (i != 0) {
      if (e[i] != e[i - 1]) {
        ans[cnt] += e[i][0] - e[i - 1][0];
      }
    }
    cnt += e[i][1];
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << '\n';
  }
}
