#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x > 10) {
      ans += x - 10;
    }
  }
  cout << ans << '\n';
}
