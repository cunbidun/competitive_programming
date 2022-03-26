#ifdef __APPLE__
#include <array>
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
}
