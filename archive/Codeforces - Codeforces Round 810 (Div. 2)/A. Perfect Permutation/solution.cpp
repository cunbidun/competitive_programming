#include <array>
#include <functional>
#include <iostream>
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
    cout << N << ' ';
    for (int i = 1; i < N; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
