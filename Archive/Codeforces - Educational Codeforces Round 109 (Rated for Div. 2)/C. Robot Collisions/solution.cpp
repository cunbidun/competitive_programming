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
    vector<pair<array<int, 2>, char>> o, e;
    vector<int> a(N);
    vector<char> c(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
      if (a[i] % 2) {
        o.push_back({{a[i], i}, c[i]});
      } else {
        e.push_back({{a[i], i}, c[i]});
      }
    }
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    vector<int> ans(N, -1);
    auto solve = [&](vector<pair<array<int, 2>, char>> v) {
      stack<pair<array<int, 2>, char>> st;
      for (int i = 0; i < (int)v.size(); i++) {
        if (!st.empty()) {
          if (st.top().second != v[i].second && st.top().second == 'R') {
            ans[v[i].first[1]] = (v[i].first[0] - st.top().first[0]) / 2;
            ans[st.top().first[1]] = (v[i].first[0] - st.top().first[0]) / 2;
            st.pop();
          } else {
            st.push(v[i]);
          }
        } else {
          st.push(v[i]);
        }
      }
      vector<array<int, 2>> L, R;
      while (!st.empty()) {
        auto top = st.top();
        if (top.second == 'L') {
          L.push_back(top.first);
        } else {
          R.push_back(top.first);
        }
        st.pop();
      }
      while (L.size() >= 2) {
        auto f = L.back();
        L.pop_back();
        auto s = L.back();
        L.pop_back();
        ans[f[1]] = s[0] - (s[0] - f[0]) / 2;
        ans[s[1]] = s[0] - (s[0] - f[0]) / 2;
      }
      reverse(R.begin(), R.end());
      while (R.size() >= 2) {
        auto f = R.back();
        R.pop_back();
        auto s = R.back();
        R.pop_back();
        ans[f[1]] = (M - s[0]) - (f[0] - s[0]) / 2;
        ans[s[1]] = (M - s[0]) - (f[0] - s[0]) / 2;
      }
      if (R.size() + L.size() == 2) {
        auto f = L.back();
        auto s = R.back();
        int res = max(f[0], M - s[0]);
        if (f[0] > M - s[0]) {
          s[0] = M - (f[0] - (M - s[0]));
          f[0] = 0;
        } else {
          f[0] = M - s[0] - f[0];
          s[0] = M;
        }
        res += (s[0] - f[0]) / 2;
        ans[f[1]] = res;
        ans[s[1]] = res;
      }
    };
    solve(e);
    solve(o);
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
