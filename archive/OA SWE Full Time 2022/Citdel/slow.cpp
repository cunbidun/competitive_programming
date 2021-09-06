#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll prime = 251;

  int N, K;
  cin >> N >> K;
  vector<int> a(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  ll MOD = 1e9 + 7;
  vector<ll> h(N), p(N);
  h[0] = a[0];
  for (int i = 1; i < N; i++) {
    h[i] = ((h[i - 1] * prime) % MOD + a[i]) % MOD;
  }
  p[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = (p[i - 1] * prime) % MOD;
  }

  ll MOD1 = 1e9 + 9;
  vector<ll> h1(N), p1(N);
  h1[0] = a[0];
  for (int i = 1; i < N; i++) {
    h1[i] = ((h1[i - 1] * prime) % MOD1 + a[i]) % MOD1;
  }
  p1[0] = 1;
  for (int i = 1; i < N; i++) {
    p1[i] = (p1[i - 1] * prime) % MOD1;
  }

  set<array<ll, 2>> s;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = i; j < N; j++) {
      if (a[j] % 2 == 1) {
        cnt++;
      }
      if (cnt > K) {
        break;
      }
      if (i == 0) {
        ll val = (h[j] * p[N - (j + 1)]) % MOD;
        ll val1 = (h1[j] * p1[N - (j + 1)]) % MOD1;
        s.insert({val, val1});
      } else {
        ll num = ((h[j] - (h[i - 1] * p[j - i + 1]) % MOD) % MOD + MOD) % MOD;
        ll val = (num * p[N - (j - i + 1)]) % MOD;
        ll num1 = ((h1[j] - (h1[i - 1] * p1[j - i + 1]) % MOD1) % MOD1 + MOD1) % MOD1;
        ll val1 = (num1 * p1[N - (j - i + 1)]) % MOD1;
        s.insert({val, val1});
      }
    }
  }
  cout << s.size() << '\n';
}
