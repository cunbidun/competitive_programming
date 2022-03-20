#ifdef __APPLE__
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif

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
  cout << a[5] << '\n';
  cout << 1 << '\n';
}
