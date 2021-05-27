#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a;
    int mn = 1e9 + 7;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      if (x <= 0) {
        a.push_back(x);
      } else {
        mn = min(mn, x);
      }
    }
    if (a.size() == 0) {
      cout << 1 << '\n';
      continue;
    }
    if (mn == 1e9 + 7) {
      cout << a.size() << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    int cur = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
      if (abs(a[i] - cur) >= mn) {
        cur = a[i];
        cnt++;
      }
    }
    cout << max((int)a.size(), cnt + 1) << '\n';
  }
}
