#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
      cin >> V[i];
    }
    vector<int> used(N + 1);
    vector<int> s;
    s.push_back(N);
    long long ans = 0;
    function<void(int)> cal = [&](int i) {
      if (i == N) {
        ans++;
        return;
      }
      if (s.size() == V[i]) {
        for (int j = s.back(); j >= 1; j--) {
          if (!used[j]) {
            used[j] = 1;
            s.push_back(j);
            cal(i + 1);
            s.pop_back();
            used[j] = 0;
          }
        }
      } else if (s.size() > V[i]) {
        for (int j = s[V[i] - 1]; j >= s[V[i]]; j--) {
          if (!used[j]) {
            vector<int> b = s;
            while (s.size() > V[i]) {
              s.pop_back();
            }
            s.push_back(j);
            used[j] = 1;
            cal(i + 1);
            used[j] = 0;
            s = b;
          }
        }
      }
    };
    cal(0);
    cout << ans % 1000000007 << '\n';
  }
}
