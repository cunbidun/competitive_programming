#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<array<int, 2>> event;
  while (Q--) {
    int l, r, x;
    cin >> l >> r >> x;
    event.push_back({l, x});
    event.push_back({r + 1, -x});
  }

  long long p = 69747782858687LL;
  auto add = [&](long long x, long long y) -> long long {
    return ((x + y) >= p ? x + y - p : x + y);
  };
  auto sub = [&](long long x, long long y) -> long long {
    return ((x - y) < 0 ? x - y + p : x - y);
  };
  sort(event.begin(), event.end());
  vector<long long> cnt(N + 1);
  vector<int> ans(N + 1);
  cnt[0] = 1;
  for (auto e : event) {
    if (e[1] > 0) {
      for (int i = N; i >= e[1]; i--) {
        cnt[i] = add(cnt[i], cnt[i - e[1]]);
      }
    } else {
      for (int i = -e[1]; i <= N; i++) {
        cnt[i] = sub(cnt[i], cnt[i + e[1]]);
      }
    }
    for (int i = 1; i <= N; i++) {
      ans[i] |= (cnt[i] != 0);
    }
  }
  vector<int> l;
  for (int i = 1; i <= N; i++) {
    if (ans[i]) {
      l.push_back(i);
    }
  }
  cout << l.size() << '\n';
  for (int i : l) {
    cout << i << ' ';
  }
  cout << '\n';
}
