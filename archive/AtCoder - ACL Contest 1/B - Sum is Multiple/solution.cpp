#include <bits/stdc++.h>

using namespace std;

vector<long long> extended_euclid_gcd(long long a, long long b) {
  long long s = 0;
  long long old_s = 1;
  long long t = 1;
  long long old_t = 0;
  long long r = b;
  long long old_r = a;

  while (r != 0) {
    long long quotient = old_r / r;
    long long temp = r;
    r = old_r - quotient * r;
    old_r = temp;
    temp = s;
    s = old_s - quotient * s;
    old_s = temp;
    temp = t;
    t = old_t - quotient * t;
    old_t = temp;
  }
  vector<long long> result;
  result.push_back(old_r);
  result.push_back(old_s);
  result.push_back(old_t);
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N;
  cin >> N;
  N = N * 2;
  long long oN = N;
  map<long long, int> mp;
  for (long long i = 2; i * i <= N; i++) {
    int cnt = 0;
    while (N % i == 0) {
      N /= i;
      cnt++;
    }
    if (cnt > 0) {
      mp[i] = cnt;
    }
  }
  if (N > 1) {
    mp[N] = 1;
  }
  vector<long long> l;
  for (auto [k, v] : mp) {
    long long cur = 1;
    while (v--) {
      cur *= k;
    }
    l.push_back(cur);
  }
  int s = l.size();
  long long ans = 1e18;
  for (int state = 0; state < (1 << s); state++) {
    long long k = 1, k1 = 1;
    for (int i = 0; i < s; i++) {
      if ((state >> i) & 1) {
        k *= l[i];
      } else {
        k1 *= l[i];
      }
    }
    if (k1 != 1) {
      vector<long long> res = extended_euclid_gcd(k, k1);
      long long num = -1 * k * res[1];
      if (num < 0) {
        num += oN;
      }
      ans = min(ans, num);
    }
  }
  cout << ans << '\n';
}
