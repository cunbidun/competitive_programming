#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  vector<int> A(N + 1);
  vector<long long> s(N + 1);
  stack<array<int, 2>> st;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    s[i] = s[i - 1] + A[i];
  }
  for (int i = 1; i <= N; i++) {
    int p = i;
    while (!st.empty()) {
      array<int, 2> t = st.top();
      long long sum = s[t[1]] - s[t[0] - 1];
      int len = t[1] - t[0] + 1;
      if (sum * (len + (i - p + 1)) > len * (sum + s[i] - s[p - 1])) {
        p = t[0];
        st.pop();
      } else {
        break;
      }
    }
    st.push({p, i});
  }
  vector<double> ans(N + 1);
  while (!st.empty()) {
    auto t = st.top();
    for (int i = t[0]; i <= t[1]; i++) {
      ans[i] = 1.0 * (s[t[1]] - s[t[0] - 1]) / (t[1] - t[0] + 1);
    }
    st.pop();
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
