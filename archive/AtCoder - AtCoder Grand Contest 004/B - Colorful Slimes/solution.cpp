/**
 *  author: cunbidun
 *  created: Saturday, 2023-02-18 14:34:20 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct min_queue {
  deque<pair<int, int>> q;
  int cnt_added = 0;
  int cnt_removed = 0;
  int size() { return cnt_added - cnt_removed; }
  void add(int new_element) {
    while (!q.empty() && q.back().first > new_element)
      q.pop_back();
    q.push_back({new_element, cnt_added});
    cnt_added++;
  }
  void remove() {
    if (!q.empty() && q.front().second == cnt_removed)
      q.pop_front();
    cnt_removed++;
  }
  int find_min() { return q.front().first; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long x;
  cin >> N >> x;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    a.push_back(a[i]);
  }
  long long ans = 1e18;
  for (int i = 1; i <= N; i++) {
    long long res = x * (i - 1);
    auto q = min_queue();
    for (int j = 0; j < N + i - 1; j++) {
      if (q.size() < i) {
        q.add(a[j]);
      }
      if (q.size() == i) {
        res += q.find_min();
        q.remove();
      }
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
}
