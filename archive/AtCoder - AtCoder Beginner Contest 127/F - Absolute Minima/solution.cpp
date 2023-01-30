/**
 *  author: cunbidun
 *  created: Saturday, 2023-01-28 14:52:55 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  long long c = 0, sum1 = 0, sum2 = 0;
  priority_queue<long long> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  for (int i = 0; i < Q; i++) {
    int q_type;
    cin >> q_type;
    if (q_type == 1) {
      int a, b;
      cin >> a >> b;
      c += b;
      if (max_heap.empty() || max_heap.top() >= a) {
        max_heap.push(a);
        sum1 += a;
      } else {
        min_heap.push(a);
        sum2 += a;
      }
      while (max_heap.size() > min_heap.size() + 1) {
        long long top = max_heap.top();
        max_heap.pop();
        min_heap.push(top);
        sum1 -= top;
        sum2 += top;
      }
      while (max_heap.size() < min_heap.size()) {
        long long top = min_heap.top();
        min_heap.pop();
        max_heap.push(top);
        sum1 += top;
        sum2 -= top;
      }
    } else {
      long long current = max_heap.top();
      cout << current << ' ' << sum2 - current * (int)min_heap.size() + current * (int)max_heap.size() - sum1 + c
           << '\n';
    }
  }
}
