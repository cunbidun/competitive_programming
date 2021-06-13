#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  if (N % 2 == 1 && K % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> f(N + 1, 1e9);
  vector<array<int, 2>> p(N + 1);
  f[K] = 1;
  f[0] = 0;
  for (int it = 1; it <= N; it++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N - K + 1; j++) {
        int c = max(0, min(j + K - 1, i) - j + 1);
        if (f[i + K - 2 * c] > f[i] + 1) {
          f[i + K - 2 * c] = min(f[i + K - 2 * c], f[i] + 1);
          p[i + K - 2 * c] = {i, j};
        }
      }
    }
  }

  vector<array<int, 2>> l;
  int cur = N;
  while (cur != K) {
    l.push_back(p[cur]);
    cur = p[cur][0];
  }
  l.push_back({0, 1});
  reverse(l.begin(), l.end());
  set<int> v;
  int ans = 0;
  for (int i = 0; i < (int)l.size(); i++) {
    int start = l[i][1];
    vector<int> skip(N + 1);
    vector<int> ask;
    int cnt = 0;
    set tmp = v;
    for (int j : v) {
      if (cnt < start - 1) {
      } else {
        ask.push_back(j);
        tmp.erase(j);
      }
      cnt++;
      skip[j] = 1;
    }
    v = tmp;
    for (int j = 1; j <= N; j++) {
      if ((int)ask.size() < K && !skip[j]) {
        ask.push_back(j);
        v.insert(j);
      }
    }
    cout << "? ";
    for (int j : ask) {
      cout << j << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    ans ^= x;
  }
  cout << "! " << ans << endl;
}
