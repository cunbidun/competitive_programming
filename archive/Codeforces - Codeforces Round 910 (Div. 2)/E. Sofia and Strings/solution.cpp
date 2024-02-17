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
    string s, t;
    cin >> s >> t;
    vector<queue<int>> pos(26);
    for (int i = 0; i < N; i++) {
      pos[s[i] - 'a'].push(i);
    }
    int f = 0;
    for (int i = 0; i < M; i++) {
      int c_index = t[i] - 'a';
      if (pos[c_index].empty()) {
        f = 1;
        break;
      }
      int current_pos = pos[c_index].front();
      pos[c_index].pop();
      for (int j = 0; j < c_index; j++) {
        while (!pos[j].empty() && pos[j].front() < current_pos) {
          pos[j].pop();
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
