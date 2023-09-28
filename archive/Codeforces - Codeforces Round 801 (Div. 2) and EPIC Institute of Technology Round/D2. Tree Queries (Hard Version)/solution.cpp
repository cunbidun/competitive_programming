/**
 *  author: cunbidun
 *  created: Saturday, 2023-09-23 23:19:25 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1);
    for (int i = 1; i < N; i++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    if (N == 1) {
      cout << 0 << '\n';
      continue;
    }
    if (N == 2) {
      cout << 1 << '\n';
      continue;
    }
    vector<int> start;
    for (int i = 1; i <= N; i++) {
      if (a[i].size() == 1) {
        start.push_back(i);
      }
    }
    vector<int> visited(N + 1);
    vector<int> cnt(N + 1);
    int total = 0;
    set<int> parent;

    for (int i : start) {
      int current = i;
      if (visited[current]) {
        continue;
      }
      int child = current;
      current = a[current][0];

      while (a[current].size() == 2) {
        int other = a[current][0];
        if (other == child) {
          other = a[current][1];
        }
        child = current;
        current = other;
        visited[current] = 1;
      }

      cnt[current]++;
      parent.insert(current);
      total++;
    }

    if (cnt[*parent.begin()] != total) {
      int ans = 0;
      for (int p : parent) {
        ans += cnt[p] - 1;
      }
      cout << ans << '\n';
    } else {
      int p0 = *parent.begin();
      if (cnt[p0] == 1) {
        cout << 1 << '\n';
      } else {
        cout << cnt[p0] - 1 << '\n';
      }
    }
  }
}
