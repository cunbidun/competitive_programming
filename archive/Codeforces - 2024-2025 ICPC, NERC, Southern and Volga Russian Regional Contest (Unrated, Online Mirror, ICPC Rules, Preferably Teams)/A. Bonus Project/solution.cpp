#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> B[i];
  }
  vector<int> C(N);
  for (int i = N - 1; i >= 0; i--) {
    C[i] = min(A[i] / B[i], K);
    K -= C[i];
  }
  if (K) {
    for (int i = 0; i < N; i++) {
      cout << 0 << ' ';
    }
    cout << '\n';
  } else {
    for (int i = 0; i < N; i++) {
      cout << C[i] << ' ';
    }
  }
}
