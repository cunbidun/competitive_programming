#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }

  vector<vector<int>> l(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      l[i][i] = 0;
      stack<int> st;
      st.push(i);
      for (int j = i + 1; j < n; j++) {
        if (a[j] == 0) {
          st.push(j);
          l[i][j] = l[i][j - 1];
        } else {
          if (st.empty()) {
            break;
          }
          l[i][j] = l[i][j - 1];
          l[i][j] += j - st.top();
          st.pop();
        }
      }
    }
  }

  vector<vector<int>> r(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      r[i][i] = 0;
      stack<int> st;
      st.push(i);
      for (int j = i - 1; j >= 0; j--) {
        if (a[j] == 0) {
          st.push(j);
          r[j][i] = r[j + 1][i];
        } else {
          if (st.empty()) {
            break;
          }
          r[j][i] = r[j + 1][i];
          r[j][i] += st.top() - j;
          st.pop();
        }
      }
    }
  }
  vector<int> f(n, 1e9);
  f[0] = a[0] * 1e9;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0) {
      f[i] = r[0][i];
      for (int j = 0; j < i; j++) {
        f[i] = min(f[i], f[j] + r[j + 1][i]);
      }
    } else {
      f[i] = l[0][i];
      for (int j = 0; j < i; j++) {
        f[i] = min(f[i], f[j] + l[j + 1][i]);
      }
    }
  }
  cout << f[n - 1] << '\n';
}
