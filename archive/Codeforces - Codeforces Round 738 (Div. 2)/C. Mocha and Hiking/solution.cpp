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
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    if (a[1] == 1) {
      cout << N + 1 << ' ';
      for (int i = 1; i <= N; i++) {
        cout << i << ' ';
      }
      cout << '\n';
    } else {
      if (a[N] == 0) {
        for (int i = 1; i <= N + 1; i++) {
          cout << i << ' ';
        }
        cout << '\n';
      } else {
        int p = 0;
        for (int i = 2; i <= N; i++) {
          if (a[i - 1] == 0 && a[i] == 1) {
            p = i - 1;
            break;
          }
        }
        for (int i = 1; i <= p; i++) {
          cout << i << ' ';
        }
        cout << N + 1 << ' ';
        for (int i = p + 1; i <= N; i++) {
          cout << i << ' ';
        }
        cout << '\n';
      }
    }
  }
}
