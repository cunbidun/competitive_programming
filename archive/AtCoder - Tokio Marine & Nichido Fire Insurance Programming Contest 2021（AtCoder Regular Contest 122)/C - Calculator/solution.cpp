#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N;
  cin >> N;
  vector<long long> v;
  v.push_back(1);
  v.push_back(1);
  while (true) {
    long long nxt = v[v.size() - 1] + v[v.size() - 2];
    v.push_back(nxt);
    if (nxt > N) {
      break;
    }
  }
  vector<int> idx;
  for (int i = (int)v.size() - 1; i >= 0; i--) {
    if (N >= v[i]) {
      N -= v[i];
      idx.push_back(i - 1);
    }
  }
  int cur = idx[0];
  int cnt = 4;
  vector<int> ans;
  vector<vector<int>> b(cur + 1);
  b[0].push_back(1);
  for (int j = 1; j <= cur; j++) {
    b[j].push_back(cnt);
    cnt = 7 - cnt;
  }
  for (int i = 1; i < (int)idx.size(); i++) {
    if (idx[i] % 2 == 0) {
      if (b.back()[0] == 3) {
        b[cur - idx[i]].push_back(1);
      } else {
        b[cur - idx[i]].push_back(2);
      }
    } else {
      if (b.back()[0] == 3) {
        b[cur - idx[i]].push_back(2);
      } else {
        b[cur - idx[i]].push_back(1);
      }
    }
  }
  for (auto bb : b) {
    for (int i : bb) {
      ans.push_back(i);
    }
  }
  ans.push_back(3);
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i << '\n';
  }
}
