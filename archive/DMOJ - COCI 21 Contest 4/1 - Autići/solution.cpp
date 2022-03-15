#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    ans += a[i] + a[0];
  }
  cout << ans << '\n';
}
