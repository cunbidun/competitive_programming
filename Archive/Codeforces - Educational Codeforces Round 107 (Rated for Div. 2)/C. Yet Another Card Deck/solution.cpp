#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> p(54, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (p[a[i]] == -1) {
      p[a[i]] = i;
    }
  }
  while (q--) {
    int t;
    cin >> t;
    for (int i = 1; i <= 50; i++) {
      if (p[i] != -1 && p[i] < p[t]) {
        p[i]++;
      }
    }
    cout << p[t] + 1 << ' ';
    p[t] = 0;
  }
  cout << '\n';
}
