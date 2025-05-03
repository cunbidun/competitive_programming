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
    vector<int> cnt(N + 1);
    for (int i = 0; i < M; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    set<pair<int, int>> items;
    for (int i = 1; i <= N; i++) {
      items.insert({cnt[i], i});
    }
    while (true) {
      auto it = items.begin();
      auto [cnt_mn, mn] = *it;
      it = items.end();
      it--;
      auto [cnt_mx, mx] = *it;
      if (mn == mx) {
        break;
      }
      if (cnt_mn + 2 >= cnt_mx) {
        break;
      }
      items.erase({cnt_mn, mn});
      items.erase({cnt_mx, mx});
      cnt[mn] += 2;
      cnt[mx]--;
      items.insert({cnt[mn], mn});
      items.insert({cnt[mx], mx});
    }
    // print the max cnt from the set
    cout << items.rbegin()->first << endl;
  }
}
