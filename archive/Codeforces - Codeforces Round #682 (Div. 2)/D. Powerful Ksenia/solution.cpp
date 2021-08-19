#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<array<int, 3>> ans;
  for (int i = 1; i + 2 <= N; i += 2) {
    int n = a[i] ^ a[i + 1] ^ a[i + 2];
    ans.push_back({i, i + 1, i + 2});
    a[i] = n;
    a[i + 1] = n;
    a[i + 2] = n;
  }
  if (N % 2 == 0) {
    if (a[N - 1] != a[N]) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = 1; i + 1 <= N - 2; i += 2) {
    int n = a[N - 1] ^ a[i] ^ a[i + 1];
    ans.push_back({i, i + 1, N});
    a[i] = n;
    a[i + 1] = n;
    a[N] = n;
  }
  cout << "YES\n";
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p[0] << ' ' << p[1] << ' ' << p[2] << '\n';
  }
}
