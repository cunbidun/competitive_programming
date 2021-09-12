#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;

    string s;
    char c;
    cin >> c;
    s += c;

    for (int i = 0; i < N - 1; i++) {
      cin >> c;
      if (c != 'F') {
        if (c != s.back()) {
          s += c;
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != 'F') {
        cnt++;
      }
    }
    cout << max(0, cnt - 1) << '\n';
  }
}
