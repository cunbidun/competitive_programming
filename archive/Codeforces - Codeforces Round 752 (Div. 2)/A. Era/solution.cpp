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
    vector<int> a(N + 1);
    int mx = 0;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      mx = max(mx, a[i] - i);
    }
    cout << mx << '\n';
  }
}
