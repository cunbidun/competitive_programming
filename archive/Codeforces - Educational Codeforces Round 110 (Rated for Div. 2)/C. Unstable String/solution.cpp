#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    int n = (int)S.size();
    vector<int> pos(n);
    for (int i = 1; i < (int)S.size(); i++) {
      if (S[i - 1] == '?') {
        pos[i] = pos[i - 1];
      } else {
        pos[i] = i;
      }
    }
    int p = 0;
    long long ans = 0;
    vector<int> par(2, -1);
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] != '?') {
        if (par[S[i] - '0'] != -1 && i % 2 != par[S[i] - '0']) {
          p = pos[i];
        }
        par[S[i] - '0'] = i % 2;
        par[1 - (S[i] - '0')] = 1 - par[S[i] - '0'];
      }
      ans += i - p + 1;
    }
    cout << ans << '\n';
  }
}
