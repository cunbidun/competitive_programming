#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    char c;
    cin >> N >> c;
    string s;
    cin >> s;
    int f = 0;
    for (int i = 0; i < N; i++) {
      if (s[i] != c) {
        f = 1;
        break;
      }
    }
    if (!f) {
      cout << 0 << '\n';
      continue;
    }
    f = 0;
    for (int i = N / 2; i < N; i++) {
      if (s[i] == c) {
        f = 1;
        cout << 1 << '\n';
        cout << i + 1 << '\n';
        break;
      }
    }
    if (f) {
      continue;
    }
    cout << 2 << '\n';
    cout << N << ' ' << N - 1 << '\n';
  }
}
