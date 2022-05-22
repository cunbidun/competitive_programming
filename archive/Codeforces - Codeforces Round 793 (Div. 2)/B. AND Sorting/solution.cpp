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
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      if (x != i) {
        a.push_back(x);
      }
    }

    int ans = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
      ans &= a[i];
    }
    cout << ans << '\n';
  }
}
