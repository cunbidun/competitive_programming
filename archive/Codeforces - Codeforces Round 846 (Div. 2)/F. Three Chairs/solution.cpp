/**
 *  author: cunbidun
 *  created: Wednesday, 2023-09-13 22:52:02 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> lp;
  vector<int> pr;
  auto sieve = [&lp, &pr](int N) {
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j) {
        lp[i * pr[j]] = pr[j];
      }
    }
  };
  sieve(300005);
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> count(3e5 + 1);
  vector<long long> pos(3e5 + 1);
  long long w = 0;
  for (int i = 0; i < N; i++) {
    int c = a[i];
    vector<int> p_list;
    while (c != 1) {
      int l = lp[c];
      p_list.push_back(l);
      while (c % l == 0) {
        c /= l;
      }
    }
    int n = p_list.size();
    for (int mask = 1; mask < (1 << n); mask++) {
      int num = 1;
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if ((mask >> j) & 1) {
          cnt++;
          num *= p_list[j];
        }
      }
      if (i >= 2) {
        if (cnt % 2 == 1) {
          w += 1LL * i * count[num] - pos[num] - count[num];
        } else {
          w -= 1LL * i * count[num] - pos[num] - count[num];
        }
      }
      count[num]++;
      pos[num] += i;
    }
  }
  cout << 1LL * N * (N - 1) * (N - 2) / 6 - w << '\n';
}
