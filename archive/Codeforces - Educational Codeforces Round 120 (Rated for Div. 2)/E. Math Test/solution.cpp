#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
      cin >> x[i];
    }
    vector<string> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int res = 0;
    int pos = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
      int base = 0;
      for (int i = 0; i < N; i++) {
        if ((mask >> i) & 1) {
          base += x[i];
        } else {
          base -= x[i];
        }
      }
      vector<array<int, 2>> w(M);
      for (int i = 0; i < M; i++) {
        w[i][1] = i;
      }
      for (int i = 0; i < N; i++) {
        int s = ((mask >> i) & 1) ? -1 : 1;
        for (int j = 0; j < M; j++) {
          w[j][0] += s * (a[i][j] - '0');
        }
      }
      sort(w.begin(), w.end());
      for (int i = 0; i < M; i++) {
        base += w[i][0] * (i + 1);
      }
      if (res < base) {
        res = base;
        pos = mask;
      }
    }

    vector<array<int, 2>> w(M);
    for (int i = 0; i < M; i++) {
      w[i][1] = i;
    }
    for (int i = 0; i < N; i++) {
      int s = ((pos >> i) & 1) ? -1 : 1;
      for (int j = 0; j < M; j++) {
        w[j][0] += s * (a[i][j] - '0');
      }
    }
    sort(w.begin(), w.end());
    vector<int> ans(M);
    for (int i = 0; i < M; i++) {
      ans[w[i][1]] = i + 1;
    }
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
