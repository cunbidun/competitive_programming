#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 2>> l;
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    l.push_back({x, i});
  }
  multiset<int> s;
  s.insert(0);
  s.insert(0);
  s.insert(N + 1);
  s.insert(N + 1);
  sort(l.begin(), l.end(), [](auto f, auto s) {
    return f[0] > s[0];
  });
  s.insert(l[0][1]);
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    s.insert(l[i][1]);
    auto it = s.lower_bound(l[i][1]);
    auto l1 = it;
    l1--;
    auto l2 = l1;
    l2--;
    auto r1 = it;
    r1++;
    auto r2 = r1;
    r2++;
    ans += 1LL * l[i][0] * (*r2 - *r1) * (*it - *l1) + 1LL * l[i][0] * (*l1 - *l2) * (*r1 - *it);
  }
  cout << ans << '\n';
}
