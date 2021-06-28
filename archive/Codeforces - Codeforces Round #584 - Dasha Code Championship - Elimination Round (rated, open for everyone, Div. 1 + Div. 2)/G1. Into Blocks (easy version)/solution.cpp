#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  vector<int> l(2e5 + 1, N), r(2e5 + 1, -1);
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    a[i] = p;
    l[p] = min(l[p], i);
    r[p] = max(r[p], i);
  }
  priority_queue<int> pq;
  int p = 0;
  int last = 0;
  int ans = 0;
  vector<int> cnt(2e5 + 1);
  for (int i = 0; i < N; i++) {
    p = max(p, r[a[i]]);
    pq.push(++cnt[a[i]]);
    if (p == i) {
      ans += i - last + 1 - pq.top();
      last = i + 1;
      pq = priority_queue<int>();
    }
  }
  cout << ans << '\n';
}
