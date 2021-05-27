#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  string S;
  cin >> N;
  cin >> S;
  string a = S.substr(0, N);
  string b = S.substr(N, 2 * N);
  vector<vector<vector<string>>> v(19, vector<vector<string>>(2));
  for (int i = 0; i < (1 << N); i++) {
    int l = __builtin_popcount(i);
    string red = "", blue = "";
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        red += a[j];
      } else {
        blue += a[j];
      }
    }
    reverse(blue.begin(), blue.end());
    v[l][0].push_back(red + blue);
  }

  for (int i = 0; i < (1 << N); i++) {
    int l = __builtin_popcount(i);
    string red = "", blue = "";
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        blue += b[j];
      } else {
        red += b[j];
      }
    }
    reverse(blue.begin(), blue.end());
    v[l][1].push_back(blue + red);
  }
  for (int i = 0; i < N; i++) {
    sort(v[i][0].begin(), v[i][0].end());
    sort(v[i][1].begin(), v[i][1].end());
  }
  long long ans = 0;
  for (int i = 0; i <= N; i++) {
    int p1 = 0, p2 = 0;
    for (int j = 0; j < (int)v[i][0].size(); j++) {
      while (p1 < v[i][1].size() && v[i][1][p1] < v[i][0][j]) {
        p1++;
      }
      while (p2 < v[i][1].size() && v[i][1][p2] <= v[i][0][j]) {
        p2++;
      }
      if (v[i][1][p1] == v[i][0][j]) {
        cout << '\n';
        ans += p2 - p1;
      }
    }
  }
  cout << ans << '\n';
}
