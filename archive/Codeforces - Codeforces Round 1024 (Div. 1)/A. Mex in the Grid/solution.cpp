#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int start = (N - 1) / 2;
    vector<vector<int>> a(N, vector<int>(N));
    int current_size = 1;
    int x = start, y = start;
    int current = 0;
    while (current < N * N) {
      for (int j = 0; j < current_size + 1; j++) {
        a[x][y] = current;
        current++;
        y++;
        if (current == N * N) {
          break;
        }
      }
      if (current == N * N) {
        break;
      }

      y--;
      x++;
      for (int j = 0; j < current_size; j++) {
        a[x][y] = current;
        current++;
        x++;
        if (current == N * N) {
          break;
        }
      }

      if (current == N * N) {
        break;
      }

      x--;
      y--;
      for (int j = 0; j < current_size; j++) {
        a[x][y] = current;
        current++;
        y--;
        if (current == N * N) {
          break;
        }
      }
      if (current == N * N) {
        break;
      }

      for (int j = 0; j < current_size + 1; j++) {
        a[x][y] = current;
        current++;
        x--;
        if (current == N * N) {
          break;
        }
      }
      current_size += 2;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}
