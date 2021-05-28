#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<int> ok(100000);
  ok[0] = 1;
  for (int i = 11; i < 100000; i++) {
    if (i >= 11) {
      ok[i] |= ok[i - 11];
    }
    if (i >= 111) {
      ok[i] |= ok[i - 111];
    }
  }
  while (T--) {
    int N;
    cin >> N;
    if (N >= 100000) {
      cout << "YES\n";
    } else {
      cout << (ok[N] ? "YES" : "NO") << '\n';
    }
  }
}
