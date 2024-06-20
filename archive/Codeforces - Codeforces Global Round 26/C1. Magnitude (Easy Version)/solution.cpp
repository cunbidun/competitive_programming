#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    using ll = long long;
    vector<ll> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<vector<ll>> f_max(N + 1, vector<ll>(3));
    vector<vector<ll>> f_min(N + 1, vector<ll>(3, 1e18));
    f_min[0][1] = 0;
    f_min[0][2] = 0;

    for (int i = 1; i <= N; i++) {
      f_max[i][1] = max({f_max[i - 1][1] + a[i], f_max[i - 1][2] + a[i]});
      f_max[i][2] = max({abs(f_max[i - 1][1] + a[i]), abs(f_max[i - 1][2] + a[i])});
      f_max[i][2] = max({f_max[i][2], abs(f_min[i - 1][1] + a[i]), abs(f_min[i - 1][2] + a[i])});

      f_min[i][1] = min({f_min[i][1], f_min[i - 1][1] + a[i], f_min[i - 1][2] + a[i]});
      f_min[i][2] = min({abs(f_max[i - 1][1] + a[i]), abs(f_max[i - 1][2] + a[i])});
      f_min[i][2] = min({f_min[i][2], abs(f_min[i - 1][1] + a[i]), abs(f_min[i - 1][2] + a[i])});
    }
    cout << max(f_max[N][1], f_max[N][2]) << '\n';
  }
}
