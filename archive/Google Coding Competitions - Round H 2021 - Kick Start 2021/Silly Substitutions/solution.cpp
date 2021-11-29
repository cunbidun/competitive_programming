#include <bits/stdc++.h>

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
    vector<int> pre(N + 2);
    vector<int> nxt(N + 2);
    vector<int> val(N + 2);
    vector<vector<int>> L(10);
    val[0] = -100;
    val[N + 1] = -100;
    pre[0] = -1;
    pre[N + 1] = N;
    nxt[0] = 1;
    nxt[N + 1] = -1;
    for (int i = 1; i <= N; i++) {
      pre[i] = i - 1;
      nxt[i] = i + 1;
      char c;
      cin >> c;
      val[i] = c - '0';
      if ((val[i - 1] + 1) % 10 == val[i]) {
        L[val[i - 1]].push_back(i - 1);
      }
    }
    while (1) {
      int changed = 0;
      for (int i = 0; i < 10; i++) {
        for (int j : L[i]) {
          if ((val[j] + 1) % 10 == val[nxt[j]]) {
            changed = 1;
            val[j] = (val[j] + 2) % 10;
            val[nxt[j]] = -100;
            pre[nxt[nxt[j]]] = j;
            nxt[j] = nxt[nxt[j]];
            if ((val[pre[j]] + 1) % 10 == val[j]) {
              L[val[pre[j]]].push_back(pre[j]);
            }
            if ((val[j] + 1) % 10 == val[nxt[j]]) {
              L[val[j]].push_back(j);
            }
          }
        }
        L[i].clear();
      }
      if (!changed) {
        break;
      }
    }
    int cur = nxt[0];
    while (cur != N + 1) {
      cout << val[cur];
      cur = nxt[cur];
    }
    cout << endl;
  }
}
