#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  long long X;
  long long s = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    s += a[i];
  }
  cin >> X;
  long long time = X / s;
  X %= s;
  long long ans = time * N;
  for (int i = 0; i < N; i++) {
    X -= a[i];
    ans++;
    if (X < 0) {
      break;
    }
  }
  cout << ans << '\n';
}
