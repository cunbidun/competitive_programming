#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <int D, typename T> struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args> Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T> struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> before(N, vector<int>(M));
    vector<vector<int>> a(N, vector<int>(min(N, M)));
    vector<array<int, 2>> l;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> before[i][j];
        l.push_back({before[i][j], j});
      }
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    set<int> col_set;
    for (auto [x, j] : l) {
      col_set.insert(j);
      if ((int)col_set.size() == N) {
        break;
      }
    }
    int cnt = 0;
    for (int j : col_set) {
      for (int i = 0; i < N; i++) {
        a[i][cnt] = before[i][j];
      }
      cnt++;
    }
    M = min(M, N);

    Vec<3, int> f(M, 1 << N, N);
    for (int offset = 0; offset < N; offset++) {
      for (int mask = 0; mask < (1 << N); mask++) {
        int cur = 0;
        for (int i = 0; i < N; i++) {
          if ((mask >> i) & 1) {
            cur += a[(i + offset) % N][0];
          }
        }
        f[0][mask][offset] = max(f[0][mask][offset], cur);
      }
    }
    for (int col = 1; col < M; col++) {
      for (int offset = 0; offset < N; offset++) {
        for (int mask = 0; mask < (1 << N); mask++) {
          for (int last_offset = 0; last_offset < N; last_offset++) {
            f[col][mask][offset] = max(f[col][mask][offset], f[col - 1][mask][last_offset]);
          }
          for (int i = 0; i < N; i++) {
            if ((mask >> i) & 1) {
              f[col][mask][offset] =
                  max(f[col][mask][offset], f[col][mask ^ (1 << i)][offset] + a[(i + offset) % N][col]);
            }
          }
        }
      }
    }
    int ans = 0;
    for (int offset = 0; offset < N; offset++) {
      for (int mask = 0; mask < (1 << N); mask++) {
        ans = max(ans, f[M - 1][mask][offset]);
      }
    }
    cout << ans << '\n';
  }
}
