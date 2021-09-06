#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<int> p(11);
  p[0] = 1;
  for (int i = 1; i < 10; i++) {
    p[i] = p[i - 1] * 10;
  }
  auto num_d = [](int n) -> int {
    if (n < 0) {
      return -1;
    }
    int cnt = 0;
    while (n) {
      cnt++;
      n /= 10;
    }
    return cnt;
  };
  while (T--) {
    int S, N;
    cin >> S >> N;
    if (N == 1) {
      cout << S << '\n';
      continue;
    }
    vector<int> v;
    for (int i = 1; i <= N - 1; i++) {
      v.push_back(1);
    }
    int c1 = S - (N - 1);
    for (int i = 0; i < (int)v.size(); i++) {
      while (true) {
        if (num_d(c1 - (v[i] * 10 - v[i])) != num_d(c1)) {
          break;
        }
        c1 -= (v[i] * 10 - v[i]);
        v[i] *= 10;
      }
    }
    cout << c1 << ' ';
    for (int i : v) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
