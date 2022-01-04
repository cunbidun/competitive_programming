#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;

  // l[i] = [j, k] subarray start at i, have j prefix and
  // currently contribute k to total
  vector<array<long long, 2>> l((int)1e5 + 5);
  vector<bool> used(1e5 + 5);

  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    vector<int> q1, q2;
    for (int i = N - 1; i >= 0; i--) {
      for (auto k : q1) {
        auto [dup, value] = l[k];
        if (k >= a[i]) {
          ans += value;
          l[a[i]][0] += dup;
          l[a[i]][1] += value;
          l[k][0] -= dup;
          l[k][1] -= value;
        } else {
          int ne = (a[i] + k - 1) / k; // number of newly created elements
          int nk = a[i] / ne;          // new key (ending)
          ans += value + dup * (ne - 1);
          l[nk][0] += dup;
          l[nk][1] += value + dup * (ne - 1);
          l[k][0] -= dup;
          l[k][1] -= value;
          if (!used[nk]) {
            used[nk] = 1;
            q2.push_back(nk);
          }
        }
      }
      l[a[i]][0] += 1;
      if (!used[a[i]]) {
        used[a[i]] = 1;
        q2.push_back(a[i]);
      }
      for (int k : q2) {
        used[k] = 0;
        if (i == 0) {
          l[k] = {0, 0};
        }
      }
      swap(q1, q2);
      q2.clear();
      ans %= 998244353;
    }
    cout << ans << '\n';
  }
}
