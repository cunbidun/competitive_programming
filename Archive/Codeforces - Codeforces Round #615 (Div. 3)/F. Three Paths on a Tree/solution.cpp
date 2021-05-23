#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> t(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    t[u].push_back(v), t[v].push_back(u);
  }
  vector<int> d(n), c(n), up(n), lvl(n), ans(n);
  int mxl, pmxl;

  function<int(int, int)> dfs = [&](int u, int l) {
    if (mxl <= lvl[u]) {
      mxl = lvl[u];
      pmxl = u;
    }
    int mx1 = 0, mx2 = 0, mx3 = 0;
    for (int v : t[u]) {
      if (v != l) {
        lvl[v] = lvl[u] + 1;
        int nxt = dfs(v, u);
        if (mx1 < nxt) {
          mx3 = mx2;
          mx2 = mx1;
          mx1 = nxt;
        } else if (mx2 < nxt) {
          mx3 = mx2;
          mx2 = nxt;
        } else {
          mx3 = max(mx3, nxt);
        }
      }
    }
    if (mx3 != 0) {
      ans[u] = mx1 + mx2 + mx3;
    }
    c[u] = mx1 + mx2;
    return d[u] = mx1 + 1;
  };
  dfs(0, 0);
  function<void(int, int)> cal = [&](int u, int l) {
    vector<int> left, right;
    for (int v : t[u]) {
      if (v != l) {
        left.push_back(d[v]);
        right.push_back(d[v]);
      } else {
        left.push_back(0);
        right.push_back(0);
      }
    }
    for (int i = 1; i < (int)left.size(); i++) {
      left[i] = max(left[i], left[i - 1]);
    }
    for (int i = (int)right.size() - 2; i >= 0; i--) {
      right[i] = max(right[i], right[i + 1]);
    }
    for (int i = 0; i < (int)t[u].size(); i++) {
      int v = t[u][i];
      if (v != l) {
        up[v] = up[u] + 1;
        if (i != 0) {
          up[v] = max(up[v], left[i - 1] + 1);
        }
        if (i != (int)t[u].size() - 1) {
          up[v] = max(up[v], right[i + 1] + 1);
        }
        cal(v, u);
      }
    }
  };
  cal(0, 0);
  int mx = 0;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    ans[i] = max(ans[i], up[i] + c[i]);
    if (ans[i] > mx) {
      mx = ans[i];
      pos = i;
    }
  }
  cout << mx << '\n';
  vector<array<int, 2>> tmp;
  set<int> s;
  for (int i : t[pos]) {
    mxl = 0;
    lvl[i] = 1;
    dfs(i, pos);
    tmp.push_back({mxl, pmxl});
  }
  sort(tmp.begin(), tmp.end());
  reverse(tmp.begin(), tmp.end());
  for (auto t : tmp) {
    s.insert(t[1]);
    if (s.size() == 3) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s.size() == 3) {
      break;
    }
    s.insert(i);
  }
  for (int i : s) {
    cout << i + 1 << ' ';
  }
  cout << '\n';
}
