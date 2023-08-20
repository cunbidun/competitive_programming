/**
 *  author: cunbidun
 *  created: Friday, 2023-07-07 19:38:06 EDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<long long> p(N), x(N), remap(N), sum(N);
    vector<array<long long, 3>> upper_event, lower_event;
    vector<array<long long, 3>> sorted_by_p;

    // Sort and make sure p[i]
    {
      for (int i = 0; i < N; i++) {
        int tmp_p, tmp_x;
        cin >> tmp_p >> tmp_x;
        sorted_by_p.push_back({tmp_p, tmp_x, i});
      }
      sort(sorted_by_p.begin(), sorted_by_p.end());
      for (int i = 0; i < N; i++) {
        p[i] = sorted_by_p[i][0];
        x[i] = sorted_by_p[i][1];
        remap[i] = sorted_by_p[i][2];
      }
    }

    // Compute the a[i]
    {
      for (int i = 0; i < N; i++) {
        upper_event.push_back({p[i], 0, i});        // 0 means opening
        upper_event.push_back({p[i], 1, i});        // 1 means snapshot
        upper_event.push_back({p[i] + x[i], 2, i}); // 2 means closing

        lower_event.push_back({p[i] - x[i], 0, i}); // 0 means opening
        lower_event.push_back({p[i], 1, i});        // 1 means snapshot
        lower_event.push_back({p[i], 2, i});        // 2 means closing
      }
      sort(upper_event.begin(), upper_event.end());
      sort(lower_event.begin(), lower_event.end());
      long long sum_p = 0, sum_x = 0, cnt = 0;
      for (auto [pos, type, idx] : upper_event) {
        if (type == 1) {
          sum[idx] += sum_x - (pos * cnt - sum_p);
        } else if (type == 0) {
          sum_p += p[idx];
          sum_x += x[idx];
          cnt++;
        } else {
          sum_p -= p[idx];
          sum_x -= x[idx];
          cnt--;
        }
      }
      sum_p = 0, sum_x = 0, cnt = 0;
      for (auto [pos, type, idx] : lower_event) {
        if (type == 2) {
          sum[idx] += sum_x - (sum_p - pos * cnt);
        } else if (type == 0) {
          sum_p += p[idx];
          sum_x += x[idx];
          cnt++;
        } else {
          sum_p -= p[idx];
          sum_x -= x[idx];
          cnt--;
        }
      }
    }

    // 1. Max only ocures at one of the locations
    // When remove day ith (covers 2 segments from p[i] - x[i] to p[i] and p[i] to p[i] + x[i])
    // Let J be the set of the locations in [p[i] - x[i], p[i]].
    // Every j in J height will be deceased by (x[i] - p[i]) + p[j]
    //
    // Let K be the set of the locations in [p[i], p[i] + x[i]].
    // Every k in K height will be deceased by (x[i] + p[i]) - p[k]

    vector<long long> zero(N), positive(N), negative(N), pref_mx(N), suff_mx(N);
    for (int i = 0; i < N; i++) {
      zero[i] = sum[i];
      positive[i] = zero[i] + p[i];
      negative[i] = zero[i] - p[i];
      pref_mx[i] = max((i > 0) ? pref_mx[i - 1] : 0, zero[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
      suff_mx[i] = max((i < N - 1) ? suff_mx[i + 1] : 0, zero[i]);
    }

    set<array<long long, 2>> s;
    for (int i = 0; i < N; i++) {
      s.insert({p[i], i});
    }
    vector<int> ans(N);

    vector<vector<long long>> st_n(N, vector<long long>(19, 1e18));
    for (int i = 0; i < N; i++) {
      st_n[i][0] = negative[i];
    }
    for (int j = 1; j <= 18; j++) {
      for (int i = 0; i + (1 << (j - 1)) < N; i++) {
        st_n[i][j] = max(st_n[i][j - 1], st_n[i + (1 << (j - 1))][j - 1]);
      }
    }
    auto rmq_n = [&](int l, int r) -> long long {
      int k = log2(r - l + 1);
      return max(st_n[l][k], st_n[r - (1 << k) + 1][k]);
    };

    vector<vector<long long>> st_p(N, vector<long long>(19, 1e18));
    for (int i = 0; i < N; i++) {
      st_p[i][0] = positive[i];
    }
    for (int j = 1; j <= 18; j++) {
      for (int i = 0; i + (1 << (j - 1)) < N; i++) {
        st_p[i][j] = max(st_p[i][j - 1], st_p[i + (1 << (j - 1))][j - 1]);
      }
    }
    auto rmq_p = [&](int l, int r) -> long long {
      int k = log2(r - l + 1);
      return max(st_p[l][k], st_p[r - (1 << k) + 1][k]);
    };

    for (int i = 0; i < N; i++) {
      long long mx = 0;

      {
        long long lower_value = p[i] - x[i];
        long long upper_value = p[i];
        auto lower_it = s.upper_bound(array<long long, 2>{lower_value, -1});
        auto upper_it = s.upper_bound(array<long long, 2>{upper_value, N});
        upper_it--;
        auto l = (*lower_it)[1];
        auto r = (*upper_it)[1];
        assert(l <= r);
        mx = max({mx, (l > 0) ? pref_mx[l - 1] : 0, rmq_n(l, r) - (x[i] - p[i])});
      }

      {
        long long lower_value = p[i];
        long long upper_value = p[i] + x[i];

        auto lower_it = s.upper_bound(array<long long, 2>{lower_value, -1});
        auto upper_it = s.upper_bound(array<long long, 2>{upper_value, N});
        upper_it--;
        auto l = (*lower_it)[1];
        auto r = (*upper_it)[1];
        assert(l <= r);
        mx = max({mx, (r < N - 1) ? suff_mx[r + 1] : 0, rmq_p(l, r) - (x[i] + p[i])});
      }

      if (mx > M) {
        ans[remap[i]] = 0;
      } else {
        ans[remap[i]] = 1;
      }
    }
    for (int i = 0; i < N; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
}
