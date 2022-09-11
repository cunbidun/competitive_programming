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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N);
    for (int i = 0; i < K; i++) {
      cin >> a[i];
    }
  }
};
