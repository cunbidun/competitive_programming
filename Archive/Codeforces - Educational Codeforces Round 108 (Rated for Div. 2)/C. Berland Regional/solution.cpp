#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    vector<int> u(n), s(n);
    for (int i = 0; i < n; i++) {
      cin >> u[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      a[u[i]].push_back(s[i]);
    }
    for (int i = 1; i <= n; i++) {
      sort(a[i].begin(), a[i].end());
      reverse(a[i].begin(), a[i].end());
    }
    vector<long long> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
      long long s = 0;
      for (int j : a[i]) {
        s += j;
      }
      set<int> st;
      for (int j = (int)a[i].size() - 1; j >= 0; j--) {
        if (st.find(j + 1) == st.end()) {
          for (int k = 1; k * k <= j + 1; k++) {
            if ((j + 1) % k == 0) {
              if (st.find(k) == st.end()) {
                cnt[k] += s;
                st.insert(k);
              }
              if (st.find((j + 1) / k) == st.end() && (j + 1) / k != k) {
                cnt[(j + 1) / k] += s;
                st.insert((j + 1) / k);
              }
            }
          }
        }
        s -= a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << cnt[i] << ' ';
    }
    cout << '\n';
  }
}
