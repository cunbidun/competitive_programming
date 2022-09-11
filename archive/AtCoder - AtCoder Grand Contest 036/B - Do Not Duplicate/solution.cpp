#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(N, vector<int>(70, 0));
  vector<vector<long long>> f(N, vector<long long>(70, 0));
  vector<int> first(2e5 + 1, -1), last(2e5 + 1, N);

  for (int i = 0; i < N; i++) {
    if (first[a[i]] == -1) {
      first[a[i]] = i;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    g[i][0] = last[a[i]];
    if (g[i][0] == N) {
      g[i][0] = first[a[i]];
      f[i][0] = 1;
    }
    if (g[i][0] == N - 1) {
      f[i][0] += 1;
    }
    g[i][0] = (g[i][0] + 1) % N;
    last[a[i]] = i;
  }
  for (int j = 1; j <= 64; j++) {
    for (int i = 0; i < N; i++) {
      g[i][j] = g[g[i][j - 1]][j - 1];
    }
  }
  for (int j = 1; j <= 64; j++) {
    for (int i = 0; i < N; i++) {
      f[i][j] = f[i][j - 1] + f[g[i][j - 1]][j - 1];
    }
  }
  auto check = [&](long long x) -> long long {
    long long total = 0;
    long long current = 0;
    for (int i = 62; i >= 0; i--) {
      if ((x >> i) & 1) {
        total += f[current][i];
        current = g[current][i];
      }
    }
    return total;
  };
  bool extra = 0;
  int pos = 0;
  if (K != 1) {
    long long l = 1, r = 1e18;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      if (check(m) <= K - 1) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    extra = check(l) < K - 1;
    for (int i = 62; i >= 0; i--) {
      if ((l >> i) & 1) {
        pos = g[pos][i];
      }
    }
  }
  vector<int> ans;
  set<int> s;
  auto compute = [&](int x) -> void {
    for (int i = x; i < N; i++) {
      if (s.find(a[i]) == s.end()) {
        s.insert(a[i]);
        ans.push_back(a[i]);
      } else {
        while (s.find(a[i]) != s.end()) {
          s.erase(ans.back());
          ans.pop_back();
        }
      }
    }
  };
  compute(pos);
  if (extra) {
    compute(0);
  }
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
