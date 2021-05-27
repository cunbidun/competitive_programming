#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long k;
  int n, m;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  vector<vector<int>> pos(1e6 + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
    pos[b[j]].push_back(j);
  }
  auto lcm = [](int a, int b) -> long long {
    return 1LL * a / __gcd(a, b) * b;
  };
  vector<long long> x(1e6 + 1, -1);
  if (n > m) {
    for (long long i = 0; i < lcm(n, m) / m; i++) {
      int ab = (1LL * i * m) % n;
      x[ab] = 1LL * i * m / n;
    }
  } else {
    for (long long i = 0; i < lcm(n, m) / n; i++) {
      int ab = (1LL * i * n) % m;
      x[ab] = 1LL * i * n / m;
    }
  }
  vector<long long> p;
  for (int i = 1; i <= 1e6; i++) {
    if ((int)pos[i].size() == 2) {
      int meet = 0;
      if (n > m) {
        meet = ((pos[i][0] - pos[i][1]) % m + m) % m;
        if (x[meet] != -1) {
          p.push_back(x[meet] * n + pos[i][0] + 1);
        }
      } else {
        meet = ((pos[i][1] - pos[i][0]) % n + n) % n;
        if (x[meet] != -1) {
          p.push_back(x[meet] * m + pos[i][1] + 1);
        }
      }
    }
  }
  long long d = lcm(n, m);
  long long l = 1, r = 1e18;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long f = 0;
    for (long long num : p) {
      if (mid >= num) {
        f += (mid - num + 1 + d - 1) / d;
      }
    }
    if (mid - f >= k) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
}
