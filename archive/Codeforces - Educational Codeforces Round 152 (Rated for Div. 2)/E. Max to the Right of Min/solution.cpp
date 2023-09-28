/**
 *  author: cunbidun
 *  created: Monday, 2023-08-21 20:21:04 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using ll = long long;
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<int> p(N + 2);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  a[0] = N + 1;
  p[N + 1] = 0;
  vector<int> mx, mn;
  mx.push_back(N + 1);
  mn.push_back(0);
  ll current_sum = 0, ans = 0;
  vector<array<int, 2>> contribute(N + 2);
  vector<int> depend_on(N + 2, -1);

  set<int> current;
  current.insert(0);

  for (int i = 1; i <= N; i++) {
    while (mx.back() < a[i]) {
      int last = mx.back();
      if (depend_on[last] != -1) {
        int e = depend_on[last];

        auto it = current.lower_bound(p[last]);
        it--;

        current_sum -= contribute[e][1];
        contribute[e] = {a[*it], p[e] - *it};
        current_sum += contribute[e][1];
        depend_on[a[*it]] = e;
      }

      if (mx.back() != mn.back()) {
        current.erase(p[mx.back()]);
      }
      mx.pop_back();
    }

    while (mn.back() > a[i]) {
      current_sum -= contribute[mn.back()][1];
      if (mx.back() != mn.back()) {
        current.erase(p[mn.back()]);
      }
      mn.pop_back();
    }
    int depend_on_e = -1;
    int depend_on_p = -1;
    if (p[mx.back()] >= p[mn.back()]) {
      depend_on_e = mx.back();
      depend_on_p = p[mx.back()];
    } else {
      depend_on_e = mn.back();
      depend_on_p = p[mn.back()];
    }
    depend_on[depend_on_e] = a[i];
    contribute[a[i]] = {depend_on_e, i - depend_on_p};
    mx.push_back(a[i]);
    mn.push_back(a[i]);
    current.insert(i);
    current_sum += contribute[a[i]][1];
    ans += current_sum - 1;
  }
  cout << ans << '\n';
}
