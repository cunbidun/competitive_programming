#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 2>> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i][0];
    a[i][1] = i;
  }
  sort(a.begin() + 1, a.end());
  vector<long long> f(N + 1);
  vector<int> t(N + 1);
  f[1] = 1e18, f[2] = 1e18;
  for (int i = 3; i <= N; i++) {
    long long mn = 1e18;
    for (int j = max(i - 5, 0); j < i - 2; j++) {
      if (mn > f[j] + a[i][0] - a[j + 1][0]) {
        mn = f[j] + a[i][0] - a[j + 1][0];
        t[i] = j + 1;
      }
    }
    f[i] = mn;
  }
  vector<int> team(N + 1);
  vector<int> l;
  int cur = N;
  while (cur > 0) {
    for (int i = t[cur]; i <= cur; i++) {
      team[a[i][1]] = cur;
    }
    l.push_back(cur);
    cur = t[cur] - 1;
  }

  map<int, int> mp;
  auto compress = [&]() {
    sort(l.begin(), l.end());
    l.resize(distance(l.begin(), unique(l.begin(), l.end())));
    for (int i : l) {
      mp[i] = mp.size() + 1;
    }
  };

  compress();
  for (int i = 1; i <= N; i++) {
    team[i] = mp[team[i]];
  }
  cout << f[N] << ' ' << mp.size() << '\n';
  for (int i = 1; i <= N; i++) {
    cout << team[i] << ' ';
  }
  cout << '\n';
}
