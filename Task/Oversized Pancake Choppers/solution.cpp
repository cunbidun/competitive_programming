#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N, D;
    cin >> N >> D;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = D - 1;
    for (int id = 0; id < N; id++) {
      for (int num_part = 1; num_part <= D; num_part++) {
        vector<long long> b = a;
        vector<bool> used(N);
        used[id] = 1;
        if (b[id] % num_part != 0) {
          for (int i = 0; i < N; i++) {
            b[i] *= num_part;
          }
        }
        int total = num_part;
        int cut = num_part - 1;
        long long sz = b[id] / num_part;
        for (int i = 0; i < N; i++) {
          if (total < D && !used[i] && b[i] % sz == 0) {
            int need = D - total;
            if (b[i] / sz <= need) {
              total += b[i] / sz;
              cut += b[i] / sz - 1;
            } else {
              cut += need;
              total = D;
            }
            used[i] = 1;
          }
        }
        if (total < D) {
          for (int i = 0; i < N; i++) {
            if (total < D && b[i] > sz && !used[i]) {
              int num_cut = min(1LL * (D - total), b[i] / sz);
              cut += num_cut;
              total += num_cut;
            }
          }
        }
        if (total == D) {
          ans = min(ans, cut);
        }
      }
    }
    cout << ans << '\n';
  }
}
