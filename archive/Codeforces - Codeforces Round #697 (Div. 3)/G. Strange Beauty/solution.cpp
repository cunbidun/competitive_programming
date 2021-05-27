#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin(), a.end());
  vector<int> f(mx + 1);
  vector<int> cnt(mx + 1);
  for (int i : a) {
    cnt[i]++;
  }
  for (int i = 1; i <= mx; i++) {
    f[i] += cnt[i];
    for (int j = i + i; j <= mx; j += i) {
      f[j] = max(f[j], f[i]);
    }
  }
  cout << n - *max_element(f.begin(), f.end()) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}