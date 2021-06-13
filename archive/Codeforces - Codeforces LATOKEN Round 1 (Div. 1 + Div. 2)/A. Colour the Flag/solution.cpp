#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    set<int> w, r;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        char x;
        cin >> x;
        if (x != '.') {
          if (x == 'W') {
            w.insert((i + j) % 2);
          } else {
            r.insert((i + j) % 2);
          }
        }
      }
    }
    if (w.size() > 1 || r.size() > 1) {
      cout << "NO\n";
      continue;
    }
    if (w.size() == 1 && r.size() == 1 && *w.begin() == *r.begin()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (w.size() == 1) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if ((i + j) % 2 == *w.begin()) {
            cout << "W";
          } else {
            cout << "R";
          }
        }
        cout << '\n';
      }
    } else if (r.size() == 1) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if ((i + j) % 2 == *r.begin()) {
            cout << "R";
          } else {
            cout << "W";
          }
        }
        cout << '\n';
      }
    } else {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if ((i + j) % 2 == 0) {
            cout << "R";
          } else {
            cout << "W";
          }
        }
        cout << '\n';
      }
    }
  }
}
