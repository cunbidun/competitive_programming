#include <bits/stdc++.h>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  auto cal = [](string s) -> vector<int> {
    vector<int> res;
    stringstream ss(s);
    while (ss.good()) {
      string i;
      getline(ss, i, ',');
      vector<int> tmp;
      stringstream sss(i);
      while (sss.good()) {
        string j;
        getline(sss, j, '-');
        tmp.push_back(stoi(j));
      }
      if (tmp.size() == 1) {
        res.push_back(tmp[0]);
      } else {
        for (int j = tmp[0]; j <= tmp[1]; j++) {
          res.push_back(j);
        }
      }
    }
    return res;
  };
  map<array<int, 3>, int> mp;
  while (t--) {
    string h, m, s;
    cin >> h >> m >> s;
    vector<int> H;
    vector<int> M;
    vector<int> S;
    if (h == "*") {
      for (int i = 0; i < 24; i++) {
        H.push_back(i);
      }
    } else {
      H = cal(h);
    }
    if (m == "*") {
      for (int i = 0; i < 60; i++) {
        M.push_back(i);
      }
    } else {
      M = cal(m);
    }
    if (s == "*") {
      for (int i = 0; i < 60; i++) {
        S.push_back(i);
      }
    } else {
      S = cal(s);
    }
    for (int i : H) {
      for (int j : M) {
        for (int k : S) {
          mp[{i, j, k}]++;
        }
      }
    }
  }
  int cnt = 0, ans = 0;
  for (int i = 0; i < 24 * 60 * 60; i++) {
    int h = i / 3600;
    int m = (i % 3600) / 60;
    int s = i % 60;
    int v = mp[{h, m, s}];
    cnt += (v != 0);
    ans += v;
  }
  cout << cnt << ' ' << ans << '\n';
}
