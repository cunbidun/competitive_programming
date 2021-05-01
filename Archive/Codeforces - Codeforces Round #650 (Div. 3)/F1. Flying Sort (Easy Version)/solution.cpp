#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    vector<int> l;
    map<int, int> mp;
    auto compress = [&]() {
      sort(l.begin(), l.end());
      l.resize(distance(l.begin(), unique(l.begin(), l.end())));
      for (int i : l) {
        mp[i] = mp.size();
      }
    };
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      l.push_back(a[i]);
    }
    compress();
    vector<int> p(N, 0);
    for (int i = 0; i < N; i++) {
      a[i] = mp[a[i]];
      p[a[i]] = i;
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
      int res = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (p[j] > p[j + 1]) {
          res += j + 1;
          break;
        }
      }
      for (int j = i + 1; j < N; j++) {
        if (p[j] < p[j - 1]) {
          res += N - j;
          break;
        }
      }
      ans = min(ans, res);
    }
    cout << ans << '\n';
  }
}
