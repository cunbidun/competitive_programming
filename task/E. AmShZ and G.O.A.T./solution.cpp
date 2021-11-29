#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<int> o(N, 0);
  int ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (o[i]) {
      continue;
    }
    for (int j = i - 2; j >= 0; j--) {
    }
  }
}
