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
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<array<long long, 2>> left(N + 2), right(N + 2);
  long long b = a[1], c = a[2];
  left[2] = {b, c};
  int p = 1;
  for (int i = 3; i <= N; i++) {
    c += a[i];
    while (abs(b - c) > abs(b + a[p + 1] - (c - a[p + 1]))) {
      b += a[p + 1];
      c -= a[p + 1];
      p++;
    }
    left[i] = {b, c};
  }
  // debug() << imie(left);

  p = N, c = a[N], b = a[N - 1];
  right[N - 1] = {b, c};
  for (int i = N - 2; i >= 1; i--) {
    b += a[i];
    while (abs(c - b) > abs(c + a[p - 1] - (b - a[p - 1]))) {
      c += a[p - 1];
      b -= a[p - 1];
      p--;
    }
    right[i] = {b, c};
  }
  long long ans = 1e18;
  for (int i = 2; i <= N - 2; i++) {
    long long mx = max({left[i][0], left[i][1], right[i + 1][0], right[i + 1][1]});
    long long mn = min({left[i][0], left[i][1], right[i + 1][0], right[i + 1][1]});
    ans = min(ans, mx - mn);
  }
  cout << ans << endl;
}
