#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K, C;
  string s;
  cin >> N >> K >> C;
  cin >> s;
  vector<int> l(K), r(K);
  int last = -1e9;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'o' && i - last > C) {
      last = i;
      l[cnt++] = i;
      if (cnt == K) {
        break;
      }
    }
  }
  cnt = K - 1;
  last = 1e9;
  for (int i = N - 1; i >= 0; i--) {
    if (s[i] == 'o' && last - i > C) {
      r[cnt--] = i;
      last = i;
      if (cnt == -1) {
        break;
      }
    }
  }
  for (int i = 0; i < K; i++) {
    if (l[i] == r[i]) {
      cout << l[i] + 1 << '\n';
    }
  }
}
