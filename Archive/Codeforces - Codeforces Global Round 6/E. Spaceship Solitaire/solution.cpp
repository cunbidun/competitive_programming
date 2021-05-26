#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N;
  vector<int> a(N + 1);
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    ans += a[i];
  }
  cin >> Q;
  vector<int> cnt(N + 1);
  map<array<int, 2>, int> mp;
  while (Q--) {
    int s, t, u;
    cin >> s >> t >> u;
    int p = mp[{s, t}];
    if (cnt[p] != 0) {
      cnt[p]--;
      ans += cnt[p] < a[p];
    }
    if (u != 0) {
      cnt[u]++;
      ans -= cnt[u] <= a[u];
    }
    mp[{s, t}] = u;
    cout << ans << '\n';
  }
}
