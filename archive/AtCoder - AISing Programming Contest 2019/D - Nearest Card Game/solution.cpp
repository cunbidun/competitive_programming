#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N + 1), s(N + 1), o(N + 1), e(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  o[1] = a[1];
  for (int i = 2; i <= N; i++) {
    o[i] = o[i - 1];
    e[i] = e[i - 1];
    if (i % 2 == 0) {
      e[i] = e[i - 1] + a[i];
    } else {
      o[i] = o[i - 1] + a[i];
    }
  }

  auto check = [&](int x, int l, int r) -> int {
    if (l > r) {
      return 0;
    }
    if (l == 0) {
      return 2;
    }
    if (abs(x - a[r + 1]) < abs(x - a[l])) {
      return -1;
    }
    if (l != 1 && (abs(x - a[l - 1]) <= abs(x - a[r]))) {
      return 1;
    }
    return 0;
  };

  while (Q--) {
    long long x;
    cin >> x;
    int l = 1, r = N / 2 + 1;
    bool off_by_one = false;

    while (l <= r) {
      int m = (l + r) / 2;
      int val = check(x, N - 2 * m + 1, N - m);

      if (val == 0) {
        l = m;
        break;
      }

      if (val == 2) {
        val = check(x, N - 2 * m + 2, N - m);
        if (val == 0) {
          l = m;
          off_by_one = true;
          break;
        }
      }
      if (val == -1) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    long long s1 = s[N] - s[N - l];
    r = ((off_by_one) ? N - l - (l - 1) : N - 2 * l);
    if (r % 2 == off_by_one) {
      s1 += e[r];
    } else {
      s1 += o[r];
    }
    cout << s1 << '\n';
  }
}
