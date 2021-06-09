#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;

  vector<int> a(N), b(N);
  vector<long long> l(N), r(N);
  long long s = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    s += a[i];
  }
  auto cal = [&](long long k) -> long long {
    for (int i = 0; i < N; i++) {
      b[i] = (a[i] % k);
    }
    int last = 0;
    long long cur = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      cur += b[i];
      if (cur >= k) {
        b[i] -= cur - k;
        long long cur_s = 0;
        long long cnt = 0;
        for (int j = last; j <= i; j++) {
          cur_s += cnt;
          cnt += b[j];
          l[j - last] = cur_s;
        }
        cnt = 0;
        cur_s = 0;
        for (int j = i; j >= last; j--) {
          cur_s += cnt;
          cnt += b[j];
          r[j - last] = cur_s;
        }
        long long res = 1e18;
        for (int j = 0; j < i - last + 1; j++) {
          res = min(res, l[j] + r[j]);
        }
        if (res == l[i - last]) {
          if (i != N - 1) {
            b[i + 1] += cur - k;
          }
          ans += cur - k;
          last = i + 1;
          cur = 0;
        } else {
          last = i;
          b[i] = cur - k;
          cur = b[i];
        }
        ans += res;
      }
    }
    return ans;
  };
  long long ans = 1e18;
  for (long long i = 2; i * i <= s; i++) {
    if (s % i == 0) {
      ans = min(ans, cal(i));
      while (s % i == 0) {
        s /= i;
      }
    }
  }
  if (s != 1) {
    ans = min(ans, cal(s));
  }
  cout << ((ans == (long long)(1e18)) ? -1 : ans) << '\n';
}
