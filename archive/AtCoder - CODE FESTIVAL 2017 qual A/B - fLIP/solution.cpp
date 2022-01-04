#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i * M + j * N - 2 * i * j == K) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}
