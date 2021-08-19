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
    if (N == 1) {
      cout << "a\n";
      continue;
    }
    for (int i = 0; i < N / 2; i++) {
      cout << 'a';
    }
    if (N % 2 == 0) {
      cout << 'b';
    } else {
      cout << "bc";
    }
    for (int i = 0; i < N / 2 - 1; i++) {
      cout << 'a';
    }
    cout << '\n';
  }
}
