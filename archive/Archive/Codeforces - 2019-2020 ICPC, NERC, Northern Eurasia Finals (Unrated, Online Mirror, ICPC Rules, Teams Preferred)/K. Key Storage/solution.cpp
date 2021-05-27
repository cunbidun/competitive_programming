#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<long long> p(21);
  p[0] = 1;
  for (int i = 1; i <= 20; i++) {
    p[i] = p[i - 1] * i;
  }
  while (T--) {
    long long N;
    cin >> N;
    vector<int> v;
    for (int i = 2; N > 0; i++) {
      v.push_back(N % i);
      N /= i;
    }
    auto cal = [&]() -> long long {
      int n = (int)v.size();
      sort(v.begin(), v.end());
      vector<int> cnt(21);
      long long res = 1;
      for (int i = n - 1; i >= 0; i--) {
        cnt[v[i]]++;
        res *= (n + 1 - max(v[i], 1) - (n - i - 1));
      }
      for (int i = 0; i < 21; i++) {
        res /= p[cnt[i]];
      }
      return res;
    };
    sort(v.begin(), v.end());
    long long ans = cal();
    if (v[0] == 0) {
      v.erase(v.begin());
      ans -= cal();
    }
    cout << ans - 1 << '\n';
  }
}
