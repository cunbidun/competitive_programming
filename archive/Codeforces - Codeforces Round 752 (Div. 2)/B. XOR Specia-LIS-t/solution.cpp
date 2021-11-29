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
    if (N % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    int ok = 0;
    for (int i = 1; i < N; i++) {
      ok |= (a[i] <= a[i - 1]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
