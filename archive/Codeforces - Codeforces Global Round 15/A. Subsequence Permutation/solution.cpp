#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    string s;
    cin >> N >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans += t[i] != s[i];
    }
    cout << ans << "\n";
  }
}
