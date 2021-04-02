#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    auto solve = [&](vector<int> box, vector<int> pos) {
      if (pos.size() == 0 || box.size() == 0) {
        return 0;
      }
      vector<int> pre_cal(pos.size() + 1);
      int p = (int)box.size() - 1;
      for (int i = (int)pos.size() - 1; i >= 0; i--) {
        pre_cal[i] = pre_cal[i + 1];
        while (p > 0 && box[p] > pos[i]) {
          p--;
        }
        if (pos[i] == box[p]) {
          pre_cal[i]++;
        }
      }
      int mx = pre_cal[0];
      p = 0;
      int cnt = 0;
      int back = 0;
      for (int i = 0; i < (int)pos.size(); i++) {
        while (p < (int)box.size() && pos[i] >= box[p]) {
          cnt++;
          p++;
        }
        while (back <= i && pos[i] - cnt + 1 > pos[back]) {
          back++;
        }
        mx = max(mx, i - back + 1 + pre_cal[i + 1]);
      }
      return mx;
    };
    vector<int> l_b, l_p;
    for (int i : a) {
      if (i > 0) {
        l_b.push_back(i);
      }
    }
    for (int i : b) {
      if (i > 0) {
        l_p.push_back(i);
      }
    }
    int ans = solve(l_b, l_p);
    l_b.clear();
    l_p.clear();
    for (int i : a) {
      if (i < 0) {
        l_b.push_back(-i);
      }
    }
    for (int i : b) {
      if (i < 0) {
        l_p.push_back(-i);
      }
    }
    reverse(l_b.begin(), l_b.end());
    reverse(l_p.begin(), l_p.end());
    cout << ans + solve(l_b, l_p) << '\n';
  }
}
