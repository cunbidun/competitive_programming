#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> n >> s;
    int m = (n + 1) / 2;
    cout << s / (n - (m - 1)) << '\n';
  }
}
