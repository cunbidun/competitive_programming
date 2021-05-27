#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, L, K;
  cin >> N >> L >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  auto check = [&](int d) -> bool {
    int cur = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (a[i] >= cur + d) {
        cnt++;
        cur = a[i];
      }
      if (cnt == K) {
        break;
      }
    }
    return cnt >= K && L - cur >= d;
  };
  int l = 1, r = L;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << '\n';
}
