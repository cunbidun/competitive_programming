#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    map<int, array<long long, 2>> l;
    for (int i = N - 1; i >= 0; i--) {
      map<int, array<long long, 2>> n;
      for (auto [k, v] : l) {
        auto [len, value] = v;
        if (k >= a[i]) {
          ans += value;
          n[a[i]][0] += len;
          n[a[i]][1] += value;
        } else {
          int ne = (a[i] + k - 1) / k;
          int nk = a[i] / ne;
          ans += value + len * (ne - 1);
          ans %= 998244353;
          n[nk][0] += len;
          n[nk][1] += value + len * (ne - 1);
        }
      }
      n[a[i]][0] += 1;
      swap(l, n);
      // debug() << imie(l);
    }
    cout << ans << '\n';
  }
}
