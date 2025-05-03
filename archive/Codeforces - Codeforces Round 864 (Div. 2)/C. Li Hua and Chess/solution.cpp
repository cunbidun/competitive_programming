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
    int d1, d2, d3;
    cout << "? 1 1" << endl;
    cin >> d1;
    cout << "? " << min(N, 1 + d1) << " " << min(M, 1 + d1) << endl;
    cin >> d2;
    cout << "? " << N << " " << 1 << endl;
    cin >> d3;
    auto dist = [&](int x, int y, int r, int c) { return max(abs(x - r), abs(y - c)); };
    vector<int> a = {d1 + 1, max(1, 1 + d1 - d2), max(1, N - d2), max(1, M - d2)};
    int px = -1, py = -1;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int f = 0;
        if (a[i] > N || a[j] > M) {
          f = 1;
        }
        if (dist(a[i], a[j], 1, 1) != d1) {
          f = 1;
        }
        if (dist(a[i], a[j], N, 1) != d3) {
          f = 1;
        }
        if (dist(a[i], a[j], min(N, 1 + d1), min(M, 1 + d1)) != d2) {
          f = 1;
        }
        if (!f) {
          px = a[i];
          py = a[j];
          break;
        }
      }
    }
    cout << "! " << px << " " << py << endl;
  }
}
