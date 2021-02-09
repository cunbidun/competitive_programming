#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &p : a) {
      cin >> p;
    }
    long long res = 0, sum = a[0];
    for (int i = 1; i < n; i++) {
      long long add = max(0LL, (1LL * a[i] * 100 + k - 1) / k - sum);
      res += add;
      sum += add + a[i];
    }
    cout << res << "\n";
  }
}
