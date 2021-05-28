#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  while (Q--) {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<int> cS(26), cT(26);
    for (int i = 0; i < N; i++) {
      cS[S[i] - 'a']++;
    }
    for (int i = 0; i < N; i++) {
      cT[T[i] - 'a']++;
    }
    int f = 0;
    for (int i = 0; i < 26; i++) {
      if (cS[i] != cT[i]) {
        f = -1;
        break;
      }
      f = max(f, cS[i]);
    }
    if (f == -1) {
      cout << "NO\n";
    } else {
      if (f > 1) {
        cout << "YES\n";
      } else {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
          int p = T.find(S[0]);
          cnt += p;
          T.erase(p, 1);
          S.erase(0, 1);
        }
        cout << ((cnt % 2 == 0) ? "YES" : "NO") << '\n';
      }
    }
  }
}
