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
    vector<int> d;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        d.push_back(
            max({i - 1 + j - 1, i - 1 + M - j, N - i + j - 1, N - i + M - j}));
      }
    }
    sort(d.begin(), d.end());
    for (int i : d) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
