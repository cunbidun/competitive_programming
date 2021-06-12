#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  long long ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < N; i++) {
    long long x;
    cin >> x;
    if (!pq.empty() && pq.top() < x) {
      ans += x - pq.top();
      pq.pop();
      pq.push(x);
    }
    pq.push(x);
  }
  cout << ans << '\n';
}
