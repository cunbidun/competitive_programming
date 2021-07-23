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
    while (N > 0 && N % 10 != 9) {
      N--;
    }
    if (N < 9) {
      cout << 0 << '\n';
      continue;
    }
    cout << (N - 9) / 10 + 1 << '\n';
  }
}
