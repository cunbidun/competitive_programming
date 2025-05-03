#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    int f = 0;
    int p = N - 1;
    for (int i = N - 1; i >= 0; i--) {
      if (S[i] == T[i]) {
        // Characters match, move to the next character in both strings
        continue;
      } else {
        p = min(p, i);
        if (S[i] == 'c' && T[i] == 'b') {
          int pos = -1;
          while (p >= 0) {
            if (S[p] == 'b') {
              pos = p;
              break;
            }
            if (S[p] == 'a') {
              break;
            }
            p--;
          }
          if (pos == -1) {
            f = 1;
            break;
          }
          swap(S[i], S[pos]);
        } else if (S[i] == 'b' && T[i] == 'a') {
          int pos = -1;
          while (p >= 0) {
            if (S[p] == 'a') {
              pos = p;
              break;
            }
            if (S[p] == 'c') {
              break;
            }
            p--;
          }
          if (pos == -1) {
            f = 1;
            break;
          }
          swap(S[i], S[pos]);
        } else {
          f = 1;
          break;
        }
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
