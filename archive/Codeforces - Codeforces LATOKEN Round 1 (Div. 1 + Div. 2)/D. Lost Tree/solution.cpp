#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  cout << "? " << 1 << endl;
  vector<int> d(N + 1);
  vector<set<int>> ans(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> d[i];
    if (d[i] == 1) {
      ans[1].insert(i);
      ans[i].insert(1);
    }
  }
  vector<int> o, e;
  for (int i = 2; i <= N; i++) {
    if (d[i] % 2 == 0) {
      e.push_back(i);
    } else {
      o.push_back(i);
    }
  }
  if (e.size() > o.size()) {
    e = o;
  }
  for (int i : e) {
    cout << "? " << i << endl;
    for (int j = 1; j <= N; j++) {
      cin >> d[j];
      if (d[j] == 1) {
        ans[i].insert(j);
        ans[j].insert(i);
      }
    }
  }
  cout << "!" << endl;
  vector<int> used(N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j : ans[i]) {
      if (!used[j]) {
        cout << i << ' ' << j << endl;
      }
    }
    used[i] = 1;
  }
}
