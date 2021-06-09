#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> a(M), p(N + 1);
  for (int i = 1; i <= N; i++) {
    p[i] = i;
  }
  vector<vector<int>> v(N + 1);
  for (int i = 0; i < M; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < M - 1; i++) {
    ans += abs(a[i] - a[i + 1]);
    if (a[i] != a[i + 1]) {
      v[a[i]].push_back(a[i + 1]);
      v[a[i + 1]].push_back(a[i]);
    }
  }
  cout << ans << ' ';
  for (int i = 2; i <= N; i++) {
    for (int j : v[i - 1]) {
      if (j != i) {
        ans += abs(p[j] - p[i]) - abs(p[j] - p[i - 1]);
      }
    }
    for (int j : v[i]) {
      if (j != i - 1) {
        ans += abs(p[j] - p[i - 1]) - abs(p[j] - p[i]);
      }
    }
    p[i] = 1;
    p[i - 1] = i;
    cout << ans << ' ';
  }
  cout << '\n';
}
