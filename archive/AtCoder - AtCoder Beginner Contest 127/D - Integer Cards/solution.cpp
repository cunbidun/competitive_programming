#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<array<int, 2>> m(M);
  for (int i = 0; i < M; i++) {
    cin >> m[i][0] >> m[i][1];
  }
  sort(m.begin(), m.end(), [](auto f, auto s) { return f[1] > s[1]; });

  int cnt = 0;
  for (int i = 0; i < M; i++) {
    cnt += m[i][0];
    for (int j = 0; j < m[i][0]; j++) {
      a.push_back(m[i][1]);
    }
    if (cnt > N) {
      break;
    }
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
}
