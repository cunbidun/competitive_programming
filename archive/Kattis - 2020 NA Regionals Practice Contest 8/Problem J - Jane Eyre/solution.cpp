#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  vector<pair<int, int>> l;
  cin >> n >> m >> k;
  string line;
  getline(cin, line);
  string s = "Jane Eyre";

  for (int i = 1; i <= n; i++) {
    getline(cin, line);
    string num = "";
    string x;
    for (int i = (int)line.size() - 1; i >= 0; i--) {
      if (line[i] == ' ') {
        x = line.substr(1, i - 2);
        break;
      }
      num = line[i] + num;
    }
    int p = stoi(num);
    if (x >= s) {
      continue;
    }
    l.push_back({0, p});
  }

  for (int i = 1; i <= m; i++) {
    getline(cin, line);
    string num = "";
    string x;
    int p1 = 0;
    for (; p1 < (int)line.size(); p1++) {
      if (line[p1] == ' ') {
        break;
      }
      num = num + line[p1];
    }
    int t = stoi(num);
    num = "";
    for (int i = line.size() - 1; i >= 0; i--) {
      if (line[i] == ' ') {
        x = line.substr(p1 + 2, i - p1 - 3);
        break;
      }
      num = line[i] + num;
    }
    int p = stoi(num);
    if (x >= s) {
      continue;
    }
    l.push_back({t, p});
  }
  long long ans = 0;
  sort(l.begin(), l.end());
  for (int i = 0; i < l.size(); i++) {
    if (ans >= l[i].first) {
      ans += l[i].second;
    } else {
      break;
    }
  }
  cout << ans + k << "\n";
}
