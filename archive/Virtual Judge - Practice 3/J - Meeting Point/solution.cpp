#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<long long, 3>> a(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a[i][0] = x + y;
    a[i][1] = x - y;
    a[i][2] = i;
  }
  vector<long long> res(N);
  sort(a.begin(), a.end());
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i][0];
    res[a[i][2]] += a[i][0] * (i + 1) - sum;
  }

  sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    sum += a[i][0];
    res[a[i][2]] += sum - a[i][0] * (N - i);
  }
  sort(a.begin(), a.end(), [](auto f, auto s) { return f[1] < s[1]; });

  sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i][1];
    res[a[i][2]] += a[i][1] * (i + 1) - sum;
  }
  sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    sum += a[i][1];
    res[a[i][2]] += sum - a[i][1] * (N - i);
  }
  long long ans = 1e18;
  for (int i = 0; i < N; i++) {
    ans = min(ans, res[i]);
  }
  cout << ans / 2 << '\n';
}
