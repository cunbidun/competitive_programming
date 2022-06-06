#include <array>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct double_inc {
  struct element {
    long long min_val, max_val, add_max, num_e;
  };
  stack<element> prev;
  long long total = 0;

  void add(long long val) {
    element cur = {val, val, 0, 1};
    while (!prev.empty()) {
      auto t = prev.top();
      int cnt = 0;

      // check  t.min_val ? cur.max_val * 2 ^ add_max
      long long lhs = t.min_val;
      while (lhs < cur.max_val) {
        cnt++;
        lhs *= 4;
      }
      long long add = 0;
      if (cnt == 0) {
        long long rhs = cur.max_val;
        while (t.min_val >= rhs) {
          cnt++;
          rhs *= 4;
        }
        cnt--;
        add = max(0LL, cur.add_max - cnt);
      } else {
        add = max(0LL, cur.add_max + cnt);
      }
      if (add > 0) {
        // over
        prev.pop();
        total += add * 2 * t.num_e;
        cur.max_val = t.max_val;
        cur.num_e += t.num_e;
        cur.add_max = t.add_max + add;
      } else {
        // under
        break;
      }
    }
    prev.push(cur);
  }

  long long get_cost() { return total; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> a(N + 1), left(N + 1, 1e18), right(N + 1, 1e18);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  double_inc from_left, from_right;
  left[0] = 0;
  right[0] = 0;
  for (int i = 1; i <= N; i++) {
    from_left.add(a[i] * 2);
    left[i] = i + from_left.get_cost();
  }
  for (int i = 1; i <= N; i++) {
    from_right.add(a[N - i + 1]);
    right[i] = from_right.get_cost();
  }
  long long ans = 1e18;
  for (int i = 0; i <= N; i++) {
    ans = min(ans, left[i] + right[N - i]);
  }
  cout << ans << '\n';
}
