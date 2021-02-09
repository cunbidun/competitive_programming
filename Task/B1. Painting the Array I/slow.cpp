#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> v0, v1;
    for (int j = 0; j < n; j++) {
      if (((i >> j) & 1) == 1) {
        v1.push_back(a[j]);
      } else {
        v0.push_back(a[j]);
      }
    }
    int res = !v1.empty() + !v0.empty(); 
    for (int j = 1; j < v1.size(); j++) {
      if (v1[j] != v1[j - 1]) {
        res++;
      }
    }
    for (int j = 1; j < v0.size(); j++) {
      if (v0[j] != v0[j - 1]) {
        res++;
      }
    }
    ans = max(ans, res);
  }
  cout << ans << "\n";
  return 0;
}
