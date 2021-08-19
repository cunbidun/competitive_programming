#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  typedef array<int, 2> point;
  vector<point> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  auto dis = [&](point a, point b) -> long long {
    return 1LL * (a[0] - b[0]) * (a[0] - b[0]) + 1LL * (a[1] - b[1]) * (a[1] - b[1]);
  };
  vector<int> used(N);
  vector<int> ans;
  used[0] = 1;
  int cur = 0;
  ans.push_back(0);
  while ((int)ans.size() < N) {
    long long mx = 0;
    int nxt = -1;
    for (int i = 0; i < N; i++) {
      if (!used[i]) {
        if (mx < dis(a[cur], a[i])) {
          mx = dis(a[cur], a[i]);
          nxt = i;
        }
      }
    }
    cur = nxt;
    used[cur] = 1;
    ans.push_back(cur);
  }
  for (int i : ans) {
    cout << i + 1 << ' ';
  }
  cout << '\n';
}
