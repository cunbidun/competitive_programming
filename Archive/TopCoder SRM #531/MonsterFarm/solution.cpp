#include <bits/stdc++.h>

using namespace std;

class MonsterFarm {
public:
  int numMonsters(vector<string> transforms) {
    int n = transforms.size();
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      stringstream ss(transforms[i]);
      int j;
      while (ss >> j) {
        j--;
        a[i].push_back(j);
      }
    }
    vector<int> visited(n);
    int f = 0;
    function<void(int, int)> dfs = [&](int u, int r) {
      visited[u] = 1;
      for (int v : a[u]) {
        if (v == r) {
          f = 1;
        }
        if (!visited[v]) {
          dfs(v, r);
        }
      }
    };
    dfs(0, 0);
    vector<int> reachable = visited;
    for (int i = 0; i < n; i++) {
      if (reachable[i]) {
        int ch = 0;
        for (int j : a[i]) {
          if (j == i) {
            ch = 1;
          }
        }
        if (ch && a[i].size() >= 2) {
          cout << -1 << '\n';
          return -1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      visited.assign(n, 0);
      f = 0;
      dfs(i, i);
      if (reachable[i] && f && a[i].size() >= 2) {
        cout << -1 << '\n';
        return -1;
      }
    }
    vector<int> val(n);
    val[0] = 1;
    for (int t = 1; t < 1000; t++) {
      vector<int> pre = val;
      val.assign(n, 0);
      for (int i = 0; i < n; i++) {
        for (int j : a[i]) {
          val[j] = (val[j] + pre[i]) % 1000000007;
        }
      }
    }
    int ans = 0;
    for (int i : val) {
      ans = (ans + i) % 1000000007;
    }
    cout << ans << '\n';
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  MonsterFarm m;

  m.numMonsters({"1"});
  m.numMonsters({"1 1"});
  m.numMonsters({"2", "3", "1"});
  m.numMonsters({"1", "3 4", "2", "2"});
  m.numMonsters({"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"});
  m.numMonsters({"2 3", "5 7", "2 4", "5", "6", "4", "7"});
}
