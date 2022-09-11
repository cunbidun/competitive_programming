#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N;
    cin >> N;
    string S;
    cin >> S;
    for (int len = 1; len <= N; len++) {
      if (len == N) {
        cout << S << '\n';
        continue;
      }
      if (N % len == 0) {
        int f = 1;
        for (int i = 0; i < N; i += len) {
          for (int j = 0; j < len; j++) {
            if (S[i + j] != S[N - len + j]) {
              f = 0;
              break;
            }
          }
        }
        if (f) {
          for (int j = 0; j < len; j++) {
            cout << S[j];
          }
          cout << '\n';
          break;
        }
      }
    }
  }
}
