#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int M, K;
  cin >> M >> K;
  if (M == 0 && K == 0) {
    cout << "0 0\n";
    return 0;
  }
  if (M == 1 && K == 0) {
    cout << "0 0 1 1\n";
    return 0;
  }
  if (M == 1 && K == 1) {
    cout << "-1\n";
    return 0;
  }
  if (K > (1 << M) - 1) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < (1 << M); i++) {
    if (i != K) {
      cout << i << ' ';
    }
  }
  cout << K << ' ';
  for (int i = (1 << M) - 1; i >= 0; i--) {
    if (i != K) {
      cout << i << ' ';
    }
  }
  cout << K << '\n';
}
