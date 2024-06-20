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
    set<int> a;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    if (a.size() == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << "RB";
      for (int i = 3; i <= N; i++) {
        cout << "R";
      }
      cout << '\n';
    }
  }
}
