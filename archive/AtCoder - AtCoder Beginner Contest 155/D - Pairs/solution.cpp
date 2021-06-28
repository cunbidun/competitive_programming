#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long K;
  cin >> N >> K;
  vector<int> p, n;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      p.push_back(x);
    } else {
      n.push_back(x);
    }
  }
  sort(p.begin(), p.end());
  sort(n.begin(), n.end(), [](int a, int b) { return a > b; });
  auto cal = [&](long long x) -> long long {
    long long res = 0;
    int r = (int)p.size() - 1;
    for (int i = 0; i < (int)p.size(); i++) {
      while (r >= i && 1LL * p[i] * p[r] > x) {
        r--;
      }
      if (r > i) {
        res += r - i;
      }
    }
    r = (int)n.size() - 1;
    for (int i = 0; i < (int)n.size(); i++) {
      while (r >= i && 1LL * n[i] * n[r] > x) {
        r--;
      }
      if (r > i) {
        res += r - i;
      }
    }
    r = 0;
    for (int i = (int)p.size() - 1; i >= 0; i--) {
      while (r < (int)n.size() && 1LL * p[i] * n[r] > x) {
        r++;
      }
      if (r < (int)n.size()) {
        res += (int)n.size() - r;
      }
    }
    return res;
  };
  long long MX = 1000000000000000000LL;
  long long l = 0, r = 2 * MX;
  while (l < r) {
    long long m = (l + r) / 2;
    if (cal(m - MX) >= K) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l - MX << '\n';
}
