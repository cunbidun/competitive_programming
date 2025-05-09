#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> a(N);
    long long S = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      S += a[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (a[i] * N > S) {
        ans++;
      }
    }
    sort(a.begin(), a.end());
    int p = N - 1;
    for (int i = N - 1; i > 1; i--) {
      S -= a[i];
      while (p >= 0 && a[p] * i > S) {
        p--;
      }
      ans = max(ans, i - 1 - p);
    }
    cout << ans << '\n';
  }
}
