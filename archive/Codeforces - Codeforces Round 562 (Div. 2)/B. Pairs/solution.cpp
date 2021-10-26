#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> c;
  vector<array<int, 2>> a;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a.push_back({u, v});
  }
  auto check = [&](int r) {
    vector<int> ch(N);
    vector<int> cnt(N);
    int count = 0;
    for (auto [x, y] : a) {
      if (x != r && y != r) {
        count++;
        cnt[x]++;
        if (y != x) {
          cnt[y]++;
        }
      }
    }
    for (int i = 0; i < N; i++) {
      if (cnt[i] == count) {
        return 1;
      }
    }
    return 0;
  };
  if (check(a[0][0]) || check(a[0][1])) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
