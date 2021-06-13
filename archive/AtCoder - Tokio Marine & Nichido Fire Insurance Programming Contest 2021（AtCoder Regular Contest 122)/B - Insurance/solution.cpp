#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  vector<long long> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  long double mx = 0;
  long double s = 0;
  long double p = 0;
  for (int i = 1; i <= N; i++) {
    s += a[i];
    long double res = s - (long double)a[i] / 2 * i + (long double)a[i] / 2 * (N - i);
    if (isgreater(res, mx)) {
      mx = res;
      p = (long double)a[i] / 2;
    }
  }
  long double ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += p + a[i] - min((long double)a[i], 2 * p);
  }
  cout << ans / N << '\n';
}
