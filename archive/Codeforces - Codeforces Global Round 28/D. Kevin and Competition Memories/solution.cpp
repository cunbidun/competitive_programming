#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    vector<int> b(M);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int k = a[0];
    for (int i = 0; i < M; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p = N - 1;
    vector<int> res;
    for (int i = M - 1; i >= 0; i--) {
      if (b[i] <= k) {
        res.push_back(1);
      } else {
        while (p >= 0 && a[p] >= b[i]) {
          p--;
        }
        res.push_back(N - 1 - p + 1);
      }
      // cout << b[i] << ' ' << res.back() << '\n';
    }
    sort(res.begin(), res.end());
    for (int i = 1; i <= M; i++) {
      long long ans = 0;
      for (int j = i; j <= M; j += i) {
        ans += res[j - 1];
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
}
