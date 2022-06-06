#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, X, D;
  cin >> N >> X >> D;
  if (D == 0) {
    if (X == 0) {
      cout << 1 << '\n';
    } else {
      cout << N + 1 << '\n';
    }
    return 0;
  }
  int g = abs(gcd(X, D));
  X /= g;
  D /= g;
  long long cur_min = 0, cur_max = N - 1;
  if (D < 0) {
    D *= -1;
    X *= -1;
  }
  long long l = 0, r = 0;
  long long tot = 1;
  vector<vector<array<long long, 2>>> list(N + 1, vector<array<long long, 2>>());
  list[0].push_back({0, 0});
  for (int i = 0; i < N; i++) {
    l += cur_min;
    r += cur_max;
    cur_min++;
    cur_max--;
    tot += r - l + 1;
    list[(i + 1) % D].push_back({l, r});
  }
  for (int div = 0; div < N; div++) {
    vector<array<long long, 2>> events;
    for (int i = 0; i < (int)list[div].size(); i++) {
      long long sz = list[div].size();
      long long st = list[div][i][0] - 1LL * (sz - 1 - i) * X;
      long long en = list[div][i][1] - 1LL * (sz - 1 - i) * X;
      events.push_back({st, -1});
      events.push_back({en + 1, 1});
    }
    sort(events.begin(), events.end());
    int num_open = 1;
    for (int i = 1; i < (int)events.size(); i++) {
      long long cur = events[i][0];
      int type = events[i][1];
      if (num_open > 0) {
        long long len = (cur - events[i - 1][0]);
        tot -= 1LL * len * (num_open - 1);
      }
      if (type == -1) {
        num_open++;
      }
      if (type == 1) {
        num_open--;
      }
    }
  }
  cout << tot << '\n';
}
